# Basic Setup

This is a repository that represent a basic, minimal, c++ project setup using cmake. This currently includes:
- Creation of a `kernel` library.
- Creation of an `api` library to expose this `kernel` library.
- Creation of a python interface to enable access to the `api` from python.

Currently only building on windows using `msbuild` has been tested.
Instructions to this regard are in the following section.

## Pre-setup requirements

Clone this repository and ensure `conda` is installed.

## Setup

1. From repository root, create conda environment: `conda env create -f environment.yml`.
   This will create a conda environment called `basic-setup`

2. Activate this conda environment: `conda activate basic-setup`.

3. Run cmake: `cmake --preset windows-default`

4. From the created `build` folder, run `msbuild`: `msbuild basicSetup.sln`

5. Add the directory of the created python interface to the python path: `set PYTHONPATH=%PYTHONPATH%;<repo root>\build\lib\Debug`

## Testing the repo setup

1. To test setup has been successfull, from the repository root run: `python -c "from basicSetupApi import helloWorld; helloWorld(<your name>)"`

