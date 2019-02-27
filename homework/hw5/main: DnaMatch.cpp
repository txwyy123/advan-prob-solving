main: DnaMatch.cpp
	echo     ------------compiling DnaMatch.cpp to create executable program main----------------
	g++  -ggdb   -std=c++11   DnaMatch.cpp   -o   DnaMatch
clean:
	echo ----------------removing executable program main--------------------
	/bin/rm DnaMatch
