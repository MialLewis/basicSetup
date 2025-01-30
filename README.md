# Basic Setup

This is a repository that represents a basic, minimal, c++ project setup using cmake and conda. This currently includes:
- Creation of a `kernel` library.
- Creation of an `api` library to expose this `kernel` library.
- Creation of a python interface to enable access to the `api` from python using pybind.
- Creation of a second python interface using boost (rough first pass)
- cppcheck

Currently only building on windows using `msbuild` and `ninja` has been tested.
Instructions to this regard are in the following section.

## Pre-setup requirements

- Clone this repository
- Ensure `conda` (or preferably `mamba`) is installed.

## Pre-setup msbuild only

- Ensure `msbuildtools` are available, and on the path. These are typically in:  `/c/Program Files/Microsoft Visual Studio/2022/Community/MSBuild/Current/Bin`


## Setup msbuild

1. From repository root, create conda environment: `conda env create -f environment.yml`.
   This will create a conda environment called `basic-setup`

2. Activate this conda environment: `conda activate basic-setup`.

3. Run cmake: `cmake --preset win-ninja`

4. From the created `build` directory, run `msbuild`: `msbuild basicSetup.sln`

5. Add the directory of the created python interface to the python path: `set PYTHONPATH=%PYTHONPATH%;<repo root>\build\lib\Debug`

## Setup ninja

1. On windows this setup must be undertaken using `x64 Native Tools Command Prompt for VS 2022`.

2. From repository root, create conda environment: `conda env create -f environment.yml`.
   This will create a conda environment called `basic-setup`

3. Activate this conda environment: `conda activate basic-setup`.

4. Run cmake: `cmake --preset win-ninja`

5. From the created `build` directory, run `ninja`

6. Add the directory of the created python interface to the python path: `set PYTHONPATH=%PYTHONPATH%;<repo root>\build\lib`

## Testing the repo setup

1. To test that the setup has been successfull, from the repository root run: `python -c "from basicSetupApi import helloWorld; helloWorld('<your name>')"`

## Running cppcheck

1. As of the latest version of cppcheck on `conda-forge`, `2.15.0`, there is a bug causing cppcheck to look for `cfg` files in the wrong location:
   https://github.com/conda-forge/cppcheck-feedstock/issues/19
   To circumvent this, we must copy the `cfg` directory from `/c/Users/<user>/AppData/Local/mambaforge/envs/basic-setup/share/Cppcheck/cfg` to a location on the
   path that cppcheck searches: `C:/Users/<user>/AppData/Local/mambaforge/envs/basic-setup/Library/bin/cfg`

2. From the `build` directory, run `cmake --build . --target cppcheck`
