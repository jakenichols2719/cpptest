# c-boilerplate

## Description

c-boilerplate provides a starting point for consistent and well-formatted C projects, built to be
lightweight and usable with minimum installation, and providing minimum project functionality to
preserve honor code guidelines for university projects.

## Setup

### Installation

1. `git init`
2. `git remote add origin [your repo]`
3. `git remote add boilerplate https://github.com/jakenichols2719/c-boilerplate.git`
4. `git fetch boilerplate`
5. `git merge boilerplate/main`

### Dependencies

The test library used for c-boilerplate is munit, which comes as a subdirectory of src/ in the installation.

The format library used for c-boilerplate is clang-format, which does NOT come along with the install. If you want
to auto-format your code, you will need to install clang.

### Upkeep

If additional tools are added to c-boilerplate, running steps 4 and 5 of the installation again should pull the latest
version from GitHub.

## Usage

The built-in makefile allows for build, test, and format features.

- `make build`: Build all source files in `src`, getting headers from `src/headers`, into `build.exe`
- `make test`: Build a test executable `test.exe` that runs all munit tests defined in `src/tests` (example provided, more thorough in `src/munit`)
- `make fmt`: Format all code in `src` using clang-format rules.