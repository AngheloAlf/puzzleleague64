/* SPDX-FileCopyrightText: © 2024 AngheloAlf */
/* SPDX-License-Identifier: MIT */

#![allow(clippy::uninlined_format_args)]

use std::fs::File;
use std::io::Write;
use std::path::Path;

use std::{
    fs::{self},
    io::{BufReader, BufWriter, Read},
};

use anyhow::Result;

pub fn read_file_bytes(path: &Path) -> Result<Vec<u8>> {
    let file = File::open(path)?;

    let mut buf_reader = BufReader::new(file);
    let mut buffer = Vec::new();

    let _ = buf_reader.read_to_end(&mut buffer);

    Ok(buffer)
}
pub fn write_file_bytes(path: &Path, b: &[u8]) -> Result<()> {
    let file = fs::OpenOptions::new().write(true).open(path)?;

    let mut buf_writer = BufWriter::new(file);

    let _ = buf_writer.write(b)?;

    Ok(())
}

pub fn hex_bytes(bs: &[u8], add_colons: bool) -> String {
    /*
    let glue = if add_colons {
        ":"
    } else {
        ""
    };

    bs.iter().map(|x| format!("{:02X}", x)).collect::<Vec<String>>().join(glue)
    */

    // TODO: this looks silly
    if add_colons {
        bs.iter()
            .map(|x| format!("{:02X}", x))
            .collect::<Vec<String>>()
            .join(":")
    } else {
        bs.iter().map(|x| format!("{:02X}", x)).collect()
    }
}
