#include "countChar.h"
#include <stdio.h>

void count(int* printable, int& space, int& other){
	char c;
	while((c = getchar()) != EOF){
		if(c >= ' ' && c <= '~')
			printable[c-' ']++;
		if(c == ' ' || c == '\t' || c == '\n')
			space++;
		if(c < ' ' || c > '~')
			other++;
	}
}

void print(int* printable, int& space, int& other){
	for(int i = 0; i < 95; i++)
		if(printable[i] != 0)
			printf("'%c': %d\n", i+' ', printable[i]);
	printf("whitespace characters: %d\n", space);
	printf("other characters: %d\n", other);
}

void doCount(){
	int printable[95] = {0};
	int space = 0;
	int other = 0;
	count(printable, space, other);
	print(printable, space, other);
}