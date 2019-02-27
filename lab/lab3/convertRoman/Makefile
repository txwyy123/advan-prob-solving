CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

main: convertRoman.cpp
	echo     ------------compiling convertRoman.cpp to create executable program main----------------
	g++  -ggdb   -std=c++11   convertRoman.cpp   -o   convertRoman
clean:
	echo ----------------removing executable program main--------------------
	/bin/rm -rf convertRoman convertRoman.dSYM