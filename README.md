# syntax-analyzer

Compiler class project

## How to use

`./syntax_analyzer <input_file>`

## How to build

Don't use `make`!! There is 2 different build configurations. Each built binary is outputted in the `./build/release/` or `./build/debug/` folder depending on the configuration. 

- debug: `./build_debug.sh` creates a debug build with AddressSanitizer *(GCC 4.8+)* to check for memory leaks, like valgrind but better.
- release: `./build_release.sh` creates a release build with most compiler optimizations.

## Install dependencies

Ubuntu
```
sudo apt install make gcc
```

Fedora
```
sudo dnf install make gcc
```

OpenSUSE
```
sudo zypper in make gcc
```

## Clone repository

```
git clone git@github.com:eretsym/syntax-analyzer.git
```

## Project structure

Please separate source files *(.c)* from header files *(.h)*, by sorting them in their respective folders (`./src` for `.c`, `./include` for `.h`). Test files should be in `./tests/` directory, if any.
```
include
 |- definitions.h
 |- xxx.h
 '- ...
src
 |- main.c
 |- xxx.c
 '- ...
tests
 |- test1.txt
 '- ...
```

Don't push `.vscode`, `./build/`