# Pokémon Puzzle League [![Build Status]][actions] ![Code usa Progress] ![Code eur Progress] ![Code fra Progress] ![Code ger Progress]

[Build Status]: <https://github.com/AngheloAlf/puzzleleague64/actions/workflows/ci.yml/badge.svg>
[actions]: <https://github.com/AngheloAlf/puzzleleague64/actions/workflows/ci.yml>
[Code usa Progress]: https://img.shields.io/endpoint?label=Code%20usa&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpuzzleleague64%2Fusa%2Fcode%2F%3Fmode%3Dshield%26measure%3Dall
[Code eur Progress]: https://img.shields.io/endpoint?label=Code%20eur&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpuzzleleague64%2Feur%2Fcode%2F%3Fmode%3Dshield%26measure%3Dall
[Code fra Progress]: https://img.shields.io/endpoint?label=Code%20fra&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpuzzleleague64%2Ffra%2Fcode%2F%3Fmode%3Dshield%26measure%3Dall
[Code ger Progress]: https://img.shields.io/endpoint?label=Code%20ger&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpuzzleleague64%2Fger%2Fcode%2F%3Fmode%3Dshield%26measure%3Dall

Matching decomp of Pokémon Puzzle League

[Progress graph :chart_with_upwards_trend:](https://angheloalf.github.io/puzzleleague64/)

## Dependencies

### System packages

The build process has the following package requirements:

* make
* git
* build-essential
* clang
* binutils-mips-linux-gnu
* gcc-mips-linux-gnu
* python3
* pip3

Under Debian / Ubuntu (which we recommend using), you can install them with the following commands:

```bash
sudo apt update
sudo apt install make git build-essential clang binutils-mips-linux-gnu gcc-mips-linux-gnu python3 python3-pip
```

### Python dependencies

To install the dependencies Python dependencies run:

```bash
pip3 install -r requirements.txt
```

### Rust dependencies

To install Rust run the following command and follow the on-screen instructions

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

The following Rust programs are required by the build process:

* pigment64

To install those programs run the following commands:

```bash
cargo install pigment64 --version ">=0.3.0,<1.*"
```

## Building

Copy your big-endian Dr Mario 64 ROM into the repository's root directory and rename it to `baserom.usa.z64`. Then run

```bash
make setup
make extract
make
```

to download the appropriate compiler versions, build libultra, extract data from the rom using splat, and build the files back into a rom. If successful, the last line of output should say

```bash
build/puzzleleague64.usa.z64: OK
```

### Other versions

By default this repository builds the USA version of this game, but it also supports the EUR, FRA and GER versions.

To build other version place your ROM in the root of the repo and rename it to `baserom.VER.z64` and pass `VERSION=VER` to the above make commands (Where VER is either EUR, FRA or GER).

## Contributing

TODO: write some contributing guidelines.

Work should be done hopefully per-file but smaller efforts are still appreciated. Just open a PR and try to address any review comments left by other contributors c:

### Important note

This matching decomp effort is being done leak-free. If you have looked/worked with leaked materials (i.e. gigaleak) then it's a shame but you can't contribute to this project.

## License

The repo is licensed under the [MIT license](LICENSE), except for files that may have its own license stated either in the top of the file or are in a folder which has its own `LICENSE` file.

One notable exception is the `src/` folder, which is licensed under the [CC0 license](src/LICENSE).
