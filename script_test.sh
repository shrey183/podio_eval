#!bin/bash

# Prerequisites

# Ask the user for root_path 
ROOT_PATH_TEMPLATE="/home/user/test_build"
read -p "Please enter ROOT path, example[$ROOT_PATH_TEMPLATE]: " ROOT_PATH

#check if path is not empty string
if [ -z $ROOT_PATH ]
then
  echo "path is empty string"
  exit
fi
#check if directory exists
if [ ! -d "$ROOT_PATH" ]
then
  echo "directory does not exist"
  exit
fi

source "$ROOT_PATH/bin/thisroot.sh"

# Check for Python version

# Check if python exists
if ! hash python
	then
		echo "python is not installed"
		exit 1
fi

# Check for correct version if it exists
ver=$(python -V 2>&1 | sed 's/.* \([0-9]\).\([0-9]\).*/\1\2/')
if [ "$ver" -lt "27" ]
	then
		echo "Need version greater than to 2.7"
		exit 1
fi

# install pyyaml
pip install pyyaml


# git clone podio to directory called test_podio
git clone https://github.com/AIDASoft/podio.git

# compile podio
cd podio
source ./init.sh
mkdir build
mkdir install
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
make -j 4 install

# Finally run unit tests
make test

