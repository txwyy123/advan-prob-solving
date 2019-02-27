CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings  -Weffc++

.SUFFIXES:.cpp .o
 
CC=g++
 
SRCS=countChar.cpp \
        main.cpp
 
OBJS=$(SRCS:.cpp=.o)
EXEC=countChar
 
start: $(OBJS)
	$(CC) -ggdb -o $(EXEC) $(OBJS)
	@echo "-----------------------------OK-----------------------"
 
.cpp.o:
	$(CC) -ggdb -Wall  -o $@ -c $<
 
clean:
	rm -rf $(EXEC) $(OBJS)