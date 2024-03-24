(unfinished)
# glang
#### Programming Language w/ LLVM

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
