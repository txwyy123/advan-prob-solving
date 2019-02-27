CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

main: average.cpp
	echo     ------------compiling main.ccp to create executable program main----------------
	g++  -ggdb   -std=c++11   average.cpp   -o   average
clean:
	echo ----------------removing executable program main--------------------
	/bin/rm average

