CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

SRCS1=parseCmd.cpp
EXEC1=parseCmd

SRCS2=testIntegers.cpp
EXEC2=testIntegers

start:	
		@echo    "------------compiling parseCmd.ccp to create executable program main----------------"
		g++ -o $(EXEC1) $(SRCS1)
		@echo    "------------compiling testIntegers.ccp to create executable program main----------------"
		g++ -o $(EXEC2) $(SRCS2)
		@echo    "-----------------------------OK-------------------------------"

clean:
		rm -rf $(EXEC1)
		rm -rf $(EXEC2)

