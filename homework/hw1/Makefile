CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

main: MusicLibrary.cpp
	echo     ------------compiling MusicLibrary.ccp to create executable program main----------------
	g++  -ggdb   -std=c++11   MusicLibrary.cpp   -o   MusicLibrary
clean:
	echo ----------------removing executable program main--------------------
	/bin/rm MusicLibrary

