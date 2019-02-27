CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant  -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

SRCS1=myString.cpp
EXEC1=myString

SRCS2=parseC.cpp
EXEC2=parseC

start:	
		@echo    "------------compiling myString.ccp to create executable program main----------------"
		g++ -o $(EXEC1) $(SRCS1)
		@echo    "------------compiling parseC.ccp to create executable program main----------------"
		g++ -o $(EXEC2) $(SRCS2)
		@echo    "-----------------------------OK-------------------------------"

clean:
		rm -rf $(EXEC1)
		rm -rf $(EXEC2)

