/* SPDX-FileCopyrightText: © 2024 AngheloAlf */
/* SPDX-License-Identifier: MIT */

#![allow(non_camel_case_types)]

/**
 * Dumb and ugly program that patches the relocs of a relocatable elf file.
 *
 * Searches for relocs that are relative to a local section of the file and
 * patches them to be relative to a symbol (if there's a symbol at that offset).
 *
 * Why do all of this? Shouldn't the compiler emit "correct" relocs by default!?
 * Well, some compilers like the KMC compiler only emits relocations to symbols
 * if those symbols are external (ie not defined in the current TU). If the
 * referenced symbols are defined in current TU then KMC emits relocs relative
 * to the _section_ itself.
 * This patching process is not required at all to build or match the game, but
 * it is done because relocs relative to sections can mess up some tools that
 * inspect the relocatable object, like asm-differ.
 * Would have been easier/simpler to patch other tools instead? Probably, but
 * here we are.
 *
 * Thanks for taking the time to read this blob. Be warned, this is the last
 * bit of documentation on this file, so I hope you are here just by curiosity
 * and not because you need to fix something or add new features. If that's the
 * case, good luck.
 */
use core::str;
use std::{io::Cursor, path::PathBuf};

use anyhow::Result;
use binrw::{
    binrw,    // #[binrw] attribute
    BinRead,  // trait for reading
    BinWrite, // trait for writing
};
use clap::Parser;
use num::FromPrimitive;
use num_derive::FromPrimitive;

use rstools::utils;

// TODO: Add program description to cli

#[derive(Parser)]
#[command()]
struct Cli {
    /// Relocatable elf file (.o)
    input: PathBuf,
}

const EI_NIDENT: usize = 16;

#[derive(Debug, Copy, Clone, PartialEq)]
pub enum DataEncoding {
    ELFDATA2LSB,
    ELFDATA2MSB,
}

impl DataEncoding {
    pub fn from(val: u8) -> Self {
        match val {
            1 => DataEncoding::ELFDATA2LSB,
            2 => DataEncoding::ELFDATA2MSB,
            _ => panic!(),
        }
    }
}

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Half(pub u16);

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Word(pub u32);

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Addr(pub u32);

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Off(pub u32);

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Section(pub u16);

impl Elf32_Half {
    pub fn from_bytes(data: &[u8], endian: &DataEncoding) -> Self {
        match endian {
            DataEncoding::ELFDATA2LSB => Self(u16::from_le_bytes(data[..2].try_into().unwrap())),
            DataEncoding::ELFDATA2MSB => Self(u16::from_be_bytes(data[..2].try_into().unwrap())),
        }
    }
}
impl Elf32_Word {
    pub fn from_bytes(data: &[u8], endian: &DataEncoding) -> Self {
        match endian {
            DataEncoding::ELFDATA2LSB => Self(u32::from_le_bytes(data[..4].try_into().unwrap())),
            DataEncoding::ELFDATA2MSB => Self(u32::from_be_bytes(data[..4].try_into().unwrap())),
        }
    }
}
impl Elf32_Addr {
    pub fn from_bytes(data: &[u8], endian: &DataEncoding) -> Self {
        match endian {
            DataEncoding::ELFDATA2LSB => Self(u32::from_le_bytes(data[..4].try_into().unwrap())),
            DataEncoding::ELFDATA2MSB => Self(u32::from_be_bytes(data[..4].try_into().unwrap())),
        }
    }
}
impl Elf32_Off {
    pub fn from_bytes(data: &[u8], endian: &DataEncoding) -> Self {
        match endian {
            DataEncoding::ELFDATA2LSB => Self(u32::from_le_bytes(data[..4].try_into().unwrap())),
            DataEncoding::ELFDATA2MSB => Self(u32::from_be_bytes(data[..4].try_into().unwrap())),
        }
    }
}

#[derive(Debug, Copy, Clone, PartialEq)]
pub struct Elf32_Ident {
    pub ident: [u8; EI_NIDENT], /* Magic number and other info */
}

impl Elf32_Ident {
    pub fn new(data: &[u8]) -> Self {
        let mut ident = [0u8; EI_NIDENT];
        ident.copy_from_slice(&data[..EI_NIDENT]);

        Self { ident }
    }

    pub fn check_magic(&self) -> bool {
        if self.ident[0] != 0x7F {
            return false;
        }
        if self.ident[1] != 0x45 {
            // 'E'
            return false;
        }
        if self.ident[2] != 0x4C {
            // 'L'
            return false;
        }
        if self.ident[3] != 0x46 {
            // 'F'
            return false;
        }
        true
    }

    pub fn endian(&self) -> DataEncoding {
        DataEncoding::from(self.ident[5])
    }
}

#[derive(Debug, Copy, Clone, PartialEq)]
/* The ELF file header.  This appears at the start of every ELF file.  */
pub struct Elf32_Ehdr {
    pub e_ident: Elf32_Ident,    /* Magic number and other info */
    pub e_type: Elf32_Half,      /* Object file type */
    pub e_machine: Elf32_Half,   /* Architecture */
    pub e_version: Elf32_Word,   /* Object file version */
    pub e_entry: Elf32_Addr,     /* Entry point virtual address */
    pub e_phoff: Elf32_Off,      /* Program header table file offset */
    pub e_shoff: Elf32_Off,      /* Section header table file offset */
    pub e_flags: Elf32_Word,     /* Processor-specific flags */
    pub e_ehsize: Elf32_Half,    /* ELF header size in bytes */
    pub e_phentsize: Elf32_Half, /* Program header table entry size */
    pub e_phnum: Elf32_Half,     /* Program header table entry count */
    pub e_shentsize: Elf32_Half, /* Section header table entry size */
    pub e_shnum: Elf32_Half,     /* Section header table entry count */
    pub e_shstrndx: Elf32_Half,  /* Section header string table index */
}

impl Elf32_Ehdr {
    pub fn new(data: &[u8]) -> Self {
        let e_ident = Elf32_Ident::new(data);
        let endian = e_ident.endian();

        Self {
            e_ident,
            e_type: Elf32_Half::from_bytes(&data[0x10..], &endian),
            e_machine: Elf32_Half::from_bytes(&data[0x12..], &endian),
            e_version: Elf32_Word::from_bytes(&data[0x14..], &endian),
            e_entry: Elf32_Addr::from_bytes(&data[0x18..], &endian),
            e_phoff: Elf32_Off::from_bytes(&data[0x1C..], &endian),
            e_shoff: Elf32_Off::from_bytes(&data[0x20..], &endian),
            e_flags: Elf32_Word::from_bytes(&data[0x24..], &endian),
            e_ehsize: Elf32_Half::from_bytes(&data[0x28..], &endian),
            e_phentsize: Elf32_Half::from_bytes(&data[0x2A..], &endian),
            e_phnum: Elf32_Half::from_bytes(&data[0x2C..], &endian),
            e_shentsize: Elf32_Half::from_bytes(&data[0x2E..], &endian),
            e_shnum: Elf32_Half::from_bytes(&data[0x30..], &endian),
            e_shstrndx: Elf32_Half::from_bytes(&data[0x32..], &endian),
        }
    }
}

#[derive(Debug, Clone)]
struct Elf32StringTable {
    pub strings: Vec<u8>,
}

impl Elf32StringTable {
    pub fn get(&self, offset: Elf32_Word) -> Result<String> {
        let null_character_index = {
            let mut i = offset.0 as usize;
            for c in &self.strings[offset.0 as usize..] {
                if *c == 0 {
                    break;
                }
                i += 1;
            }
            i
        };

        Ok(String::from_utf8(
            self.strings[offset.0 as usize..null_character_index].to_vec(),
        )?)
    }
}

#[derive(FromPrimitive, Debug, Copy, Clone, PartialEq)]
enum Elf32SectionType {
    SHT_NULL = 0,
    SHT_PROGBITS = 1,
    SHT_SYMTAB = 2,
    SHT_STRTAB = 3,
    SHT_RELA = 4,
    SHT_HASH = 5,
    SHT_DYNAMIC = 6,
    SHT_NOTE = 7,
    SHT_NOBITS = 8,
    SHT_REL = 9,
    SHT_SHLIB = 10,
    SHT_DYNSYM = 11,
    // 12
    // 13
    SHT_INIT_ARRAY = 14,
    SHT_FINI_ARRAY = 15,
    SHT_PREINIT_ARRAY = 16,
    SHT_GROUP = 17,
    SHT_SYMTAB_SHNDX = 18,
    SHT_NUM = 19,
}

/* Section header.  */
#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
struct Elf32_Shdr {
    pub sh_name: Elf32_Word,      /* Section name (string tbl index) */
    pub sh_type: Elf32_Word,      /* Section type */
    pub sh_flags: Elf32_Word,     /* Section flags */
    pub sh_addr: Elf32_Addr,      /* Section virtual addr at execution */
    pub sh_offset: Elf32_Off,     /* Section file offset */
    pub sh_size: Elf32_Word,      /* Section size in bytes */
    pub sh_link: Elf32_Word,      /* Link to another section */
    pub sh_info: Elf32_Word,      /* Additional section information */
    pub sh_addralign: Elf32_Word, /* Section alignment */
    pub sh_entsize: Elf32_Word,   /* Entry size if section holds table */
}

#[derive(Debug, Clone)]
struct Elf32SectionHeader {
    pub shdr: Elf32_Shdr,

    name: String,
}

impl Elf32SectionHeader {
    pub fn new(shdr: Elf32_Shdr, shstrtab: &Elf32StringTable) -> Self {
        Self {
            shdr,
            name: shstrtab.get(shdr.sh_name).unwrap(),
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn header_type(&self) -> Option<Elf32SectionType> {
        Elf32SectionType::from_u32(self.shdr.sh_type.0)
    }
}

/*
impl std::fmt::Display for Elf32SectionHeader {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.name)
    }
}
*/

#[derive(FromPrimitive, Debug, Copy, Clone, PartialEq)]
pub enum MIPSRelocs {
    R_MIPS_NONE = 0,     /* No reloc */
    R_MIPS_16 = 1,       /* Direct 16 bit */
    R_MIPS_32 = 2,       /* Direct 32 bit */
    R_MIPS_REL32 = 3,    /* PC relative 32 bit */
    R_MIPS_26 = 4,       /* Direct 26 bit shifted */
    R_MIPS_HI16 = 5,     /* High 16 bit */
    R_MIPS_LO16 = 6,     /* Low 16 bit */
    R_MIPS_GPREL16 = 7,  /* GP relative 16 bit */
    R_MIPS_LITERAL = 8,  /* 16 bit literal entry */
    R_MIPS_GOT16 = 9,    /* 16 bit GOT entry */
    R_MIPS_PC16 = 10,    /* PC relative 16 bit */
    R_MIPS_CALL16 = 11,  /* 16 bit GOT entry for function */
    R_MIPS_GPREL32 = 12, /* GP relative 32 bit */

    R_MIPS_GOT_HI16 = 22,
    R_MIPS_GOT_LO16 = 23,
    R_MIPS_CALL_HI16 = 30,
    R_MIPS_CALL_LO16 = 31,
}

/* Relocation table entry without addend (in section of type SHT_REL).  */
#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
struct Elf32_Rel {
    pub r_offset: Elf32_Addr, /* Address */
    r_info: Elf32_Word,       /* Relocation type and symbol index */
}

impl Elf32_Rel {
    pub fn r_sym(&self) -> u32 {
        self.r_info.0 >> 8
    }
    pub fn r_type(&self) -> u32 {
        self.r_info.0 & 0xFF
    }

    pub fn set_r_info(&mut self, sym: u32, typ: u32) {
        self.r_info = Elf32_Word((sym << 8) | (typ & 0xFF));
    }

    pub fn set_r_sym(&mut self, sym: u32) {
        self.set_r_info(sym, self.r_type());
    }

    #[allow(dead_code)]
    pub fn set_r_type(&mut self, typ: u32) {
        self.set_r_info(self.r_sym(), typ);
    }

    pub fn mips_reloc(&self) -> Option<MIPSRelocs> {
        MIPSRelocs::from_u32(self.r_type())
    }
}

/* How to extract and insert information held in the st_info field.  */
#[derive(FromPrimitive, Debug, Copy, Clone, PartialEq)]
pub enum SymbolBind {
    STB_LOCAL = 0,  /* Local symbol */
    STB_GLOBAL = 1, /* Global symbol */
    STB_WEAK = 2,   /* Weak symbol */
}

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */
#[derive(FromPrimitive, Debug, Copy, Clone, PartialEq)]
pub enum SymbolType {
    STT_NOTYPE = 0,  /* Symbol type is unspecified */
    STT_OBJECT = 1,  /* Symbol is a data object */
    STT_FUNC = 2,    /* Symbol is a code object */
    STT_SECTION = 3, /* Symbol associated with a section */
    STT_FILE = 4,    /* Symbol's name is file name */
    STT_COMMON = 5,  /* Symbol is a common data object */
    STT_TLS = 6,     /* Symbol is thread-local data object*/
}

/* Symbol table entry.  */

#[binrw]
#[derive(Debug, Copy, Clone, PartialEq)]
struct Elf32_Sym {
    pub st_name: Elf32_Word,     /* Symbol name (string tbl index) */
    pub st_value: Elf32_Addr,    /* Symbol value */
    pub st_size: Elf32_Word,     /* Symbol size */
    pub st_info: u8,             /* Symbol type and binding */
    pub st_other: u8,            /* Symbol visibility */
    pub st_shndx: Elf32_Section, /* Section index */
}

#[derive(Debug, Clone)]
struct Elf32SymbolEntry {
    pub sym: Elf32_Sym,

    name: String,
}

impl Elf32SymbolEntry {
    pub fn new(sym: Elf32_Sym, strtab: &Option<Elf32StringTable>) -> Self {
        let name = match strtab {
            Some(tab) => tab.get(sym.st_name).unwrap(),
            None => "".to_string(),
        };

        Self { sym, name }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn st_bind(&self) -> u8 {
        self.sym.st_info >> 4
    }

    pub fn st_type(&self) -> u8 {
        self.sym.st_info & 0xF
    }

    pub fn sym_bind(&self) -> Option<SymbolBind> {
        SymbolBind::from_u8(self.st_bind())
    }

    pub fn sym_type(&self) -> Option<SymbolType> {
        SymbolType::from_u8(self.st_type())
    }
}

fn main() {
    let cli = Cli::parse();

    let mut elf_bytes = utils::read_file_bytes(&cli.input).unwrap();

    let elf_header = Elf32_Ehdr::new(&elf_bytes);

    let endian = match elf_header.e_ident.endian() {
        DataEncoding::ELFDATA2LSB => binrw::Endian::Little,
        DataEncoding::ELFDATA2MSB => binrw::Endian::Big,
    };

    let mut section_headers_temp = Vec::new();
    for i in 0..elf_header.e_shnum.0 {
        let offset = elf_header.e_shoff.0 as usize + (i * 0x28) as usize;

        let shdr =
            Elf32_Shdr::read_options(&mut Cursor::new(&elf_bytes[offset..]), endian, ()).unwrap();

        section_headers_temp.push(shdr);
    }

    let shstrtab_sh = &section_headers_temp[elf_header.e_shstrndx.0 as usize];

    let shstrtab = Elf32StringTable {
        strings: elf_bytes[shstrtab_sh.sh_offset.0 as usize
            ..shstrtab_sh.sh_offset.0 as usize + shstrtab_sh.sh_size.0 as usize]
            .into(),
    };

    let mut section_headers = Vec::new();
    for sh in section_headers_temp {
        let x = Elf32SectionHeader::new(sh, &shstrtab);
        // println!("{}", x.name());
        section_headers.push(x);
    }

    let mut strtab: Option<Elf32StringTable> = None;
    for sh in &section_headers {
        match sh.header_type() {
            Some(Elf32SectionType::SHT_STRTAB) => {
                if sh.name() == ".strtab" {
                    strtab = Some(Elf32StringTable {
                        strings: elf_bytes[sh.shdr.sh_offset.0 as usize
                            ..sh.shdr.sh_offset.0 as usize + sh.shdr.sh_size.0 as usize]
                            .into(),
                    });
                }
            }
            _ => {}
        }
    }

    let mut symtab = Vec::new();
    for sh in &section_headers {
        match sh.header_type() {
            Some(Elf32SectionType::SHT_SYMTAB) => {
                for i in 0..sh.shdr.sh_size.0 / sh.shdr.sh_entsize.0 {
                    let offset = sh.shdr.sh_offset.0 as usize + (i * sh.shdr.sh_entsize.0) as usize;

                    let sym =
                        Elf32_Sym::read_options(&mut Cursor::new(&elf_bytes[offset..]), endian, ())
                            .unwrap();

                    symtab.push(Elf32SymbolEntry::new(sym, &strtab));
                }
            }
            _ => {}
        }
    }

    for sh in &section_headers {
        match sh.header_type() {
            Some(Elf32SectionType::SHT_REL) => {
                for i in 0..sh.shdr.sh_size.0 / sh.shdr.sh_entsize.0 {
                    let rel_offset =
                        sh.shdr.sh_offset.0 as usize + (i * sh.shdr.sh_entsize.0) as usize;

                    let mut rel = Elf32_Rel::read_options(
                        &mut Cursor::new(&elf_bytes[rel_offset..]),
                        endian,
                        (),
                    )
                    .unwrap();

                    if let Some(sym) = symtab.get(rel.r_sym() as usize) {
                        match sym.sym_type() {
                            Some(SymbolType::STT_SECTION) => {
                                match rel.mips_reloc() {
                                    Some(MIPSRelocs::R_MIPS_26) => {
                                        //println!("{}", sym.name());
                                        if sym.sym_bind() == Some(SymbolBind::STB_LOCAL) {
                                            if let Some(referenced_section) =
                                                section_headers.get(sym.sym.st_shndx.0 as usize)
                                            {
                                                let instruction_offset =
                                                    (referenced_section.shdr.sh_offset.0
                                                        + rel.r_offset.0)
                                                        as usize;

                                                let word = Elf32_Word::from_bytes(
                                                    &elf_bytes[instruction_offset..],
                                                    &elf_header.e_ident.endian(),
                                                );
                                                let computed_addend = (word.0 & 0x3FFFFFF) << 2;

                                                //println!("{} + 0x{:X}", referenced_section.name(), computed_addend);

                                                if let Some((sym_index, _refer)) =
                                                    find_referenced_sym_index(
                                                        &symtab,
                                                        sym,
                                                        computed_addend,
                                                    )
                                                {
                                                    // rintln!("0x{:08X} {} + 0x{:X} -> {} ({})", rel.r_offset.0, referenced_section.name(), computed_addend, refer.name(), sym_index);

                                                    rel.set_r_sym(sym_index);

                                                    let cleared = word.0 & !0x3FFFFFF;
                                                    let replacement_bytes =
                                                        match elf_header.e_ident.endian() {
                                                            DataEncoding::ELFDATA2LSB => {
                                                                cleared.to_le_bytes()
                                                            }
                                                            DataEncoding::ELFDATA2MSB => {
                                                                cleared.to_be_bytes()
                                                            }
                                                        };

                                                    elf_bytes.splice(
                                                        instruction_offset..instruction_offset + 4,
                                                        replacement_bytes,
                                                    );

                                                    rel.write_options(
                                                        &mut Cursor::new(
                                                            &mut elf_bytes[rel_offset..],
                                                        ),
                                                        endian,
                                                        (),
                                                    )
                                                    .unwrap();
                                                } else {
                                                    //println!("Not found: {} + 0x{:X}", referenced_section.name(), adcomputed_addenddend);
                                                }
                                            }
                                        }
                                    }
                                    _ => {}
                                }
                            }
                            _ => {}
                        }
                    }
                }
            }
            _ => {}
        }
    }

    utils::write_file_bytes(&cli.input, &elf_bytes).unwrap();
}

fn find_referenced_sym_index<'s>(
    symtab: &'s [Elf32SymbolEntry],
    sym: &Elf32SymbolEntry,
    computed_addend: u32,
) -> Option<(u32, &'s Elf32SymbolEntry)> {
    for (sym_index, aux_sym) in symtab.iter().enumerate() {
        if aux_sym.sym_type() != Some(SymbolType::STT_SECTION)
            && aux_sym.sym.st_shndx == sym.sym.st_shndx
            && aux_sym.sym.st_value.0 == computed_addend
        {
            // Avoid using a branch label or a .NON_MATCHING symbol
            if !aux_sym.name().contains('.') {
                return Some((sym_index as u32, aux_sym));
            }
        }
    }

    None
}
