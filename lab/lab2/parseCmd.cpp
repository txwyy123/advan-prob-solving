#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void linefeed(string &line, int &i){
	bool isNextChar = i < line.length()-1 && line[i+1] != ' ' && line[i+1] != '<' && line[i+1] != '>' && line[i+1] != '|' && line[i+1] != '&';
	bool isCurChar = line[i] != ' ' && line[i] != '<' && line[i] != '>' && line[i] != '|' && line[i] != '&';
	if((line[i] == ' ') || (isNextChar && isCurChar)){

	}else{
		cout << endl;
	}
}

void parseCmd(string & line){
	for(int i = 0; i < line.length(); i++){
		switch(line[i]){
			case ' ':
				break;
			default:
				cout << line[i];break;
		}
		linefeed(line, i);
	}
}

int main(int argc, char** argv){
	string line;
	while(getline(cin, line))
		parseCmd(line);
}