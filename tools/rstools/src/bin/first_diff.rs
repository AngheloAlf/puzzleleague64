/* SPDX-FileCopyrightText: © 2024 AngheloAlf */
/* SPDX-License-Identifier: MIT */

use std::{
    cmp::min,
    collections::HashSet,
    path::{Path, PathBuf},
    process::exit,
};

use anyhow::anyhow;
use anyhow::Result;
use clap::Parser;

use rstools::utils;

#[derive(Clone, Debug, clap::ValueEnum)]
enum Endianness {
    Big,
    Little,
}

// TODO: Add more arguments? Maybe rom offset, current section, etc
type ByteConverterFunc = fn(&[u8; 4], &mapfile_parser::MapFile) -> Option<String>;

fn print_diffed_word(
    built_bytes: &[u8; 4],
    expected_bytes: &[u8; 4],
    built_map_file: &mapfile_parser::MapFile,
    expected_map_file: &mapfile_parser::MapFile,
    add_colons: bool,
    bytes_converter_callback: Option<ByteConverterFunc>,
) {
    println!(
        "Bytes: {} vs {}",
        utils::hex_bytes(expected_bytes, add_colons),
        utils::hex_bytes(built_bytes, add_colons)
    );
    if let Some(callback) = bytes_converter_callback {
        if let Some(expected_converted) = callback(expected_bytes, expected_map_file) {
            if let Some(built_converted) = callback(built_bytes, built_map_file) {
                println!("{} vs {}", expected_converted, built_converted);
            }
        }
    }
    println!();
}

fn do_first_diff_impl(
    map_path: &Path,
    expected_map_path: &Path,
    rom_path: &Path,
    expected_rom_path: &Path,
    diff_count: usize,
    allow_mismatch_size: bool,
    add_colons: bool,
    bytes_converter_callback: Option<ByteConverterFunc>,
    endian: Endianness,
) -> Result<i32> {
    if !map_path.exists() {
        return Err(anyhow!("map_path ({:?}) must exist", map_path));
    }
    if !expected_map_path.exists() {
        return Err(anyhow!(
            "expected_map_path ({:?}) must exist",
            expected_map_path
        ));
    }
    if !rom_path.exists() {
        return Err(anyhow!("rom_path ({:?}) must exist", rom_path));
    }
    if !expected_rom_path.exists() {
        return Err(anyhow!(
            "expected_rom_path ({:?}) must exist",
            expected_rom_path
        ));
    }

    let built_rom = utils::read_file_bytes(rom_path)?;
    let expected_rom = utils::read_file_bytes(expected_rom_path)?;

    if built_rom.len() != expected_rom.len() {
        println!("Modified ROM has different size...");
        println!(
            "It should be 0x{:X} but it is 0x{:X}",
            expected_rom.len(),
            built_rom.len()
        );
        if !allow_mismatch_size {
            return Ok(1);
        }
    }

    if built_rom == expected_rom {
        println!("No differences!");
        return Ok(0);
    }

    let built_map_file = {
        let mut temp = mapfile_parser::MapFile::new();
        temp.read_map_file(map_path.into());
        temp
    };
    let expected_map_file = {
        let mut temp = mapfile_parser::MapFile::new();
        temp.read_map_file(expected_map_path.into());
        temp
    };

    let endian_diff = match endian {
        Endianness::Big => 0,
        Endianness::Little => 3,
    };

    let mut map_search_diff = HashSet::new();
    let mut diffs = 0;
    let shift_cap = 1000;
    let offset_skip = 24;

    for i in (offset_skip..(min(built_rom.len(), expected_rom.len()))).step_by(4) {
        let expected_bytes = &expected_rom[i..i + 4];
        let built_bytes = &built_rom[i..i + 4];

        if diffs <= shift_cap && expected_bytes != built_bytes {
            if diffs == 0 {
                let extra_message =
                    if let Some(vrom_info) = built_map_file.find_symbol_by_vram_or_vrom(i as u64) {
                        &format!(", {}", vrom_info.get_as_str_plus_offset(None))
                    } else {
                        ""
                    };
                println!("First difference at ROM address 0x{:X}{}", i, extra_message);
                print_diffed_word(
                    built_bytes.try_into()?,
                    expected_bytes.try_into()?,
                    &built_map_file,
                    &expected_map_file,
                    add_colons,
                    bytes_converter_callback,
                );
            }
            diffs += 1;
        }

        if (map_search_diff.len() < diff_count)
            && (built_rom[i + endian_diff] >> 2 != expected_rom[i + endian_diff] >> 2)
        {
            if let Some(vrom_info) = built_map_file.find_symbol_by_vram_or_vrom(i as u64) {
                let vrom_message = vrom_info.get_as_str();

                if !map_search_diff.contains(&vrom_message) {
                    map_search_diff.insert(vrom_message);

                    println!(
                        "Instruction difference at ROM addr 0x{:X}, {}",
                        i,
                        vrom_info.get_as_str_plus_offset(None)
                    );

                    print_diffed_word(
                        built_bytes.try_into()?,
                        expected_bytes.try_into()?,
                        &built_map_file,
                        &expected_map_file,
                        add_colons,
                        bytes_converter_callback,
                    );
                }
            }
        }

        if (map_search_diff.len() >= diff_count) && diffs > shift_cap {
            break;
        }
    }

    if diffs == 0 {
        println!("No differences but ROMs differ?");
        return Ok(1);
    }

    println!();
    let definite_shift = diffs > shift_cap;
    if definite_shift {
        println!("Over {} differing words, must be a shifted ROM.", shift_cap);
    } else {
        println!("{} differing word(s).", diffs);
    }

    if diffs > 100 {
        if let Some((sym, file, prev_sym)) =
        built_map_file.find_lowest_differing_symbol(expected_map_file)
        {
            let extra_message = if let Some(prev) = prev_sym {
                format!(" -- in {}?", prev.name)
            } else {
                "".to_string()
            };
            println!(
                "Map appears to have shifted just before {} ({:?}){}",
                sym.name, file.filepath, extra_message
            );
            return Ok(1);
        } else {
            println!("No ROM shift{}", if definite_shift { " (!?)" } else { "" });
        }
    }

    Ok(0)
}

/*
// TODO: Add program description to cli

#[derive(Parser)]
#[command()]
struct Cli {
    /// Path to a map file
    mapfile: PathBuf,
    /// Path to the map file in the expected dir
    expectedmap: PathBuf,
    /// Path to built ROM
    rompath: PathBuf,
    /// Path to the expected ROM
    expectedrom: PathBuf,

    /// find up to this many instruction difference(s)
    #[arg(short, long, default_value_t=5)]
    count: usize,

    /// Do not exit early if the ROM sizes does not match
    #[arg(short, long)]
    mismatch_size: bool,

    /// Specify endianness of the binary
    #[arg(short, long, value_enum, default_value_t=Endianness::Big)]
    endian: Endianness,
}

fn main() {
    let cli = Cli::parse();

    exit(do_first_diff_impl(&cli.mapfile, &cli.expectedmap, &cli.rompath, &cli.expectedrom, cli.count, cli.mismatch_size, false, None, cli.endian).unwrap());
}
*/

/// Find the first difference(s) between the expected ROM and the built ROM.
#[derive(Parser)]
#[command()]
struct Cli {
    /// Which version should be processed
    #[arg(short, long, default_value = "usa")]
    version: String,

    /// find up to this many instruction difference(s)
    #[arg(short, long, default_value_t = 5)]
    count: usize,

    /// Do not exit early if the ROM sizes does not match
    #[arg(short, long)]
    mismatch_size: bool,

    /// Specify endianness of the binary
    #[arg(short, long, value_enum, default_value_t=Endianness::Big)]
    endian: Endianness,
}

fn disassemble_word(bs: &[u8; 4], map_file: &mapfile_parser::MapFile) -> Option<String> {
    let word = u32::from_be_bytes(*bs);
    let vram = 0x80000000;
    let instr_cat = rabbitizer::InstrCategory::CPU;
    let instr = rabbitizer::Instruction::new(word, vram, instr_cat);

    if !instr.is_valid() {
        return None;
    }

    let mut imm_override = None;
    if instr.is_jump_with_address() {
        // Instruction is a function call (jal)

        // Get the embedded address of the function call
        // let sym_address = instr.getInstrIndexAsVram();
        let sym_address = instr.instr_index_as_vram();

        // Search for the address in the mapfile
        if let Some(sym_info) = map_file.find_symbol_by_vram_or_vrom(sym_address as u64) {
            // Use the symbol from the mapfile instead of a raw value
            imm_override = Some(sym_info.symbol.name);
        }
    }

    Some(instr.disassemble(imm_override.as_deref(), -20))
}

fn main() {
    let cli = Cli::parse();

    let build_folder = PathBuf::from("build");
    let expected_folder = PathBuf::from("expected");

    let rom_path = {
        let mut temp = build_folder.clone();
        temp.push(&cli.version);
        temp.push(format!("puzzleleague64.{}.z64", &cli.version));
        temp
    };
    let map_path = {
        let mut temp = build_folder.clone();
        temp.push(&cli.version);
        temp.push(format!("puzzleleague64.{}.map", &cli.version));
        temp
    };

    let expected_rom_path = {
        let mut temp = expected_folder.clone();
        temp.push(&rom_path);
        temp
    };
    let expected_map_path = {
        let mut temp = expected_folder.clone();
        temp.push(&map_path);
        temp
    };

    exit(
        do_first_diff_impl(
            &map_path,
            &expected_map_path,
            &rom_path,
            &expected_rom_path,
            cli.count,
            cli.mismatch_size,
            false,
            Some(disassemble_word),
            cli.endian,
        )
        .unwrap(),
    );
}
