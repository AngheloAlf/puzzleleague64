# Pokémon Puzzle League

[![Build Status]][actions]
[![Code usa Progress]](https://decomp.dev/AngheloAlf/puzzleleague64/usa)
[![Code eur Progress]](https://decomp.dev/AngheloAlf/puzzleleague64/eur)
[![Code fra Progress]](https://decomp.dev/AngheloAlf/puzzleleague64/fra)
[![Code ger Progress]](https://decomp.dev/AngheloAlf/puzzleleague64/ger)

[Build Status]: <https://github.com/AngheloAlf/puzzleleague64/actions/workflows/ci.yml/badge.svg>
[actions]: <https://github.com/AngheloAlf/puzzleleague64/actions/workflows/ci.yml>
[Code usa Progress]: https://decomp.dev/AngheloAlf/puzzleleague64/usa.svg?mode=shield&label=usa&measure=matched_code_percent
[Code eur Progress]: https://decomp.dev/AngheloAlf/puzzleleague64/eur.svg?mode=shield&label=eur&measure=matched_code_percent
[Code fra Progress]: https://decomp.dev/AngheloAlf/puzzleleague64/fra.svg?mode=shield&label=fra&measure=matched_code_percent
[Code ger Progress]: https://decomp.dev/AngheloAlf/puzzleleague64/ger.svg?mode=shield&label=ger&measure=matched_code_percent

Matching decomp of Pokémon Puzzle League

[Progress graph :chart_with_upwards_trend:](https://decomp.dev/AngheloAlf/puzzleleague64?mode=history)

[Legacy progress graph :chart_with_upwards_trend:](https://angheloalf.github.io/puzzleleague64/)

## Dependencies

### System packages

The build process has the following package requirements:

* make
* git
* build-essential
* wget
* clang
* binutils-mips-linux-gnu
* gcc-mips-linux-gnu
* Rust

Under Debian / Ubuntu (which we recommend using), you can install most of them
with the following commands:

```bash
sudo apt update
sudo apt install make git build-essential wget clang binutils-mips-linux-gnu gcc-mips-linux-gnu
```

### `uv`

We use `uv` to manage Python and its dependencies.

See the official `uv` docs to install it:
<https://docs.astral.sh/uv/getting-started/installation/>

Then run `uv sync` to install and update Python and any dependency needed.

If you need to run any Python script directly you can use either
`uv run ./script.py` or enable the venv in your shell.

### Rust dependencies

To install Rust, run the following command and follow the on-screen
instructions (same as official docs from <https://rustup.rs/>):

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

## Building

Copy your big-endian Pokémon Puzzle League ROM into the repository's `config/usa`
directory and rename it to `baserom.usa.z64`. Then run the following commands to
download the appropriate compiler versions, extract ROM data using splat, and
build the files back into a rom.

You can pass `-j N`, where `N` is the number of cores your processor has (you
can know this value by using the `nproc` command), to speedup the build by
parallelizing.

```bash
make setup
make extract
make
```

If successful, the last line of output should say:

```bash
build/usa/puzzleleague64.usa.z64: OK
```

### Other versions

By default this repository builds the USA version of this game, but it can also
build the `eur`, `fra` and `ger` versions.

To build other versions, place your ROM in the `config/VER/` directory (where
`VER` corresponds to the specific version of your ROM) of the repo and rename it
to `baserom.VER.z64`.
Then run all the above `make` comands, but passing the `VERSION=VER` flag to
them to build each version respectively.

## DWARF

This repository uses the DWARF debugging information contained in the
`PANEPON.plf` binary from the "Nintendo Puzzle Collection" Gamecube game as a
reference for naming symbols and structs.

Even if at a first glance Panel de Pon and Puzzle League may seem like
different games, they share big chunks of the same codebase.

You can access the DWARF dump in this repository:
<https://github.com/AngheloAlf/puzzle_collection_dwarf>

## Contributing

TODO: write some contributing guidelines.

Small efforts are appreciated. Just open a PR and try to address any review comments left by other contributors c:

### Important note

This matching decomp effort is being done leak-free. If you have looked/worked with leaked materials (i.e. gigaleak) then it's a shame but you can't contribute to this project.

## License

The repo is licensed under the [MIT license](LICENSE), except for files that may have its own license stated either in the top of the file or are in a folder which has its own `LICENSE` file.

One notable exception is the `src/` folder, which is licensed under the [CC0 license](src/LICENSE).
