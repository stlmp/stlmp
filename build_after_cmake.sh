# define colors
red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`

if [ -d "build" ]; then
	echo 'directory build exists'
	cd build
	echo 'running make'
	make
	if [ $? -eq 0 ]; then
	    printf "${green}make succeeded, running tests${reset}\n"
	    ./unit_tests
	else
	    printf "${red}make failed${reset}\n"
	fi
else
	printf "${red}build directory doesn't wxist. Please execute build.sh file instead of this one${reset}\n"
fi
