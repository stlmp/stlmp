#!/usr/bin/env bash

# define colors
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

# create build directory
if [[ -d "build" ]]; then
	echo 'directory build exists, so not creating again'
else
	mkdir build
fi

echo 'cd to build directory'
cd build

echo 'cleaning build dir'
rm -r *

echo 'running cmake'
cmake ..

if [[ $? -eq 0 ]]; then
    printf "${green}cmake succeeded${reset}\n"
	echo 'running make'
	make
	if [[ $? -eq 0 ]]; then
	    printf "${green}make succeeded, running tests${reset}\n"
	    env CTEST_OUTPUT_ON_FAILURE=1 make test
	else
	    printf "${red}make failed${reset}\n"
	fi
else
    printf "${red}cmake failed${reset}\n"
fi
