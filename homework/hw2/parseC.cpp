#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

using namespace std;

bool commentStart = false;

void space(){
	//do nothing
}

void number(string line, int &index){
	while(index < line.length() && isdigit(line[index]))
		cout << line[index++];
	cout << endl;
	index--;
}

void identifier(string line, int &index){
	while(index < line.length() && (isalpha(line[index]) || line[index] == '_'))
		cout << line[index++];
	cout << endl;
	index--;
}

void character(string line, int &index){
	for(int i = 0; i < 3; i++){
		cout << line[index];
		index++;
	}
	if(line[index] == '\'')
		cout << line[index];
	else
		index--;
	cout << endl;
}

void _string(string line, int &index){
	cout << line[index];
	index++;
	while(true){
		cout << line[index];
		if(line[index] == '\"' && line[index-1] != '\\')
			break;
		index++;
	}
	cout << endl;
}

void singleSym(string line, int &index){
	cout << line[index] << endl;;
}

void comment(string line, int &index){
	commentStart = line[index] == '/' ? true : false;
	if(!commentStart)
		index++;
}

void doubleSym(string line, int &index){
	if(index+1 < line.length()){
		if((line[index+1] == '=' || line[index] == line[index+1]) && !commentStart){
			cout << line[index];
			index++;
			cout << line[index] << endl;return;
		}else if((line[index] == '/' && line[index+1] == '*') || (line[index] == '*' && line[index+1] == '/')){
			comment(line, index);return;
		}
	}
	if(!commentStart)
		cout << line[index] << endl;
}

void parseLine(string line){
	for(int i = 0; i < line.length(); i++){
		char c = line[i];
		if(c == ' ' || c == '\n' || c == '\t'){
			space();
		}else if(c >= '0' && c <= '9' && !commentStart){
			number(line, i);
		}else if(((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') && !commentStart){
			identifier(line, i);
		}else if(c == '\'' && !commentStart){
			character(line, i);
		}else if(c == '\"' && !commentStart){
			_string(line, i);
		}else if((c == '?' || c == '~' || c == '#' || c == '[' || c == ']' || c == '{' || c == '}' 
			|| c == '(' || c == ')' || c == ';' || c == ':' || c == '>' || c == '<' || c == '.' || c == ',') && !commentStart){
			singleSym(line, i);
		}else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '=' 
			|| c == '&' || c == '|' || c == '^' || c == '%' || c == '!'){
			doubleSym(line, i);
		}
	}
}

int main(int argc, char** argv){
	string line;
	while(getline(cin, line))
		parseLine(line);
}