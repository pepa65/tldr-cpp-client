# tldr c client <a href='https://travis-ci.org/tldr-pages/tldr-cpp-client'><img src='https://travis-ci.org/tldr-pages/tldr-cpp-client.svg' align="right"></a>

A command line client for tldr, written in plain ISO C90.

## Installing

On OS X, the client can be installed through [homebrew](http://brew.sh/).

```
# To install latest development version
brew install tldr --HEAD

# To install the latest stable release
brew install tldr
```

To build the latest version from source:
```
git clone https://github.com/tldr-pages/tldr-cpp-client.git tldr-c-client
cd tldr-c-client

./deps.sh           # install dependencies
make                # build tldr
make install        # install tldr
```

The default prefix for installation is `/usr/local/bin`.

## Building

Building the `tldr` client is pretty straightforward.

#### Requirements

- `clang`/`gcc`
- `libcurl` (`brew install curl` / `apt-get install libcurl-dev` / `apt-get install libcurl4-openssl-dev`)
- `libzip` (`brew install libzip` / `apt-get install libzip-dev`)
- `pkg-config` (`brew install pkg-config` / `apt-get install pkg-config`)

#### Compiling

The [`Makefile`](https://github.com/tldr-pages/tldr-cpp-client/blob/master/Makefile)
in the root directory has all you need for builing the project.

Just call `make` and `tldr` will build itself.

```
make
```

## Autocompletion

Autocompletion is supported for `bash`, `zsh`, and `fish` and can be added by sourcing
the correct autocompletion file.

The files `autocomplete.zsh`, `autocomplete.bash`, and `autocomplete.fish` can be found in the `autocomplete`
folder in the root of the repository.

#### Installation

To install the autocompletion, just move the script for your shell to a an easy
to access directory (like your home directory), and source it in your `.bashrc` or `.zshrc`.

Example for zsh:

```
mv autocomplete/complete.zsh ~/.tldr.complete
echo "source ~/.tldr.complete" >> ~/.zshrc
```

## Usage

```
Usage: ./tldr [OPTION]... TITLE

Available options:
    -v, --verbose            Print verbose output
    -V, --version            Print version and exit
    -h, --help               Print this help and exit
    -u, --update             Update local database
    -c, --clear-cache        Clear local database
    -r PATH, --render=PATH   Render a local page for testing purposes
    -p PLATFORM, --platform=PLATFORM
                             Select platform: linux / osx / sunos / common
```

## Contributing

Please read the [CONTRIBUTING.md](https://github.com/tldr-pages/tldr-cpp-client/blob/master/CONTRIBUTING.md) for details.

## License

The MIT License (MIT) - see [LICENSE](https://github.com/tldr-pages/tldr-cpp-client/blob/master/LICENSE) for details.

