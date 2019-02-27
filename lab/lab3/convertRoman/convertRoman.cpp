#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int map(char c){
	switch(c){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
	}
	return 0;
}

void parseRoman(string line){
	int i = 0;
	int num = 0;
	while(i < line.length()){
		if(i == line.length()-1 || (map(line[i+1]) <= map(line[i])))
			num += map(line[i++]);
		else{
			num += map(line[i+1])-map(line[i]);
			i += 2;
		}
	}
	cout << line << " => " << num << endl;
}

int main(int argc, char** argv){
	string line;
	while(getline(cin, line))
		parseRoman(line);
}