(unfinished)

<div align="center">

<img width=200 src="https://www.pngkey.com/png/full/177-1779903_g-logo-g-logo-png.png" />
	
</div>

## FAQ

## Quick Start

## Installing from Source

### Dependencies
Make sure you have installed these dependencies:
- `python` 3 or 2.7
- `git`
- A C compiler (when building for the host, `cc` is enough; cross-compiling may need additional compilers)
- `curl` (not needed on windows)
- `pkg-config` if you are compiling on Linux and targeting Linux
- `libiconv` (already included with glibc on Debian-based distros)

### Building on a Unix-like System
1. Clone the **[source]()** with `git`:
```sh
git clone https://github.com/grhx/glang.git
cd glang
```
2. Configure the build settings:
3. Build and install:

### Building on Windows
On Windows, we suggest using **[winget](https://github.com/microsoft/winget-cli)** to install dependencies by running the following in a terminal:
```powershell
winget install -e Python.Python.3
winget install -e Kitware.CMake
winget install -e Git.Git
```

#### MinGW
**[MSYS2](https://www.msys2.org/)** can be used to easily build Glang on Windows:

#### MSVC
MSVC builds of Glang additionally require an installation of Visual Studio 2017 (or later) so glang's compiler can use its linker. The simplest way is to get **[Visual Studio](https://visualstudio.microsoft.com/downloads/)**, check the "C++ build tools" and "Windows 10 SDK" workload.

(If you're installing CMake yourself, be careful that "C++ CMake tools for Windows" doesn't get included under "Individual components".)

#### Specifying an ABI

### Configure and Make

### Building Documentation

## Contributing
Are you interested in contributing to Glang? There are many ways to contribute and we appreciate all of them. The best way to get started is by asking for help in the **[#new-contributors]()** Discord channel.

Documentation for contributing to the compiler or tooling is located in the Guide to Glang Development. Documentation for the standard library in the Standard library developers Guide.

Please read [CONTRIBUTING.md](/CONTRIBUTING.md) for details on this topic.

## Glang Repos
**[/glang-com - Glang.com Source Code]()**

**[/glang-vscode - Glang VSCode Extension]()**

## Credits

### Contributors

### Supporters

#### Support the Project

### Sponsors

### Software

### License
