CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

main: parseURL.cpp
	echo     ------------compiling parseURL.cpp to create executable program main----------------
	g++  -ggdb   -std=c++11   parseURL.cpp   -o   parseURL
clean:
	echo ----------------removing executable program main--------------------
	/bin/rm -rf parseURL parseURL.dSYM