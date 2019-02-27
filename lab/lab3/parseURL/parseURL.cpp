#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int stateMachine[8][5] = {
						{0,1,2,3,4},
						{5,-1,7,-1,-1},
						{2,-1,2,3,4},
						{3,-1,-1,-1,4},
						{4,-1,-1,-1,-1},
						{5,-1,2,-1,-1},
						{6,5,2,-1,-1},
						{-1,-1,6,-1,-1}
					   };
string scheme, domain, port, path, queryString, fragmentId;
string temp;

void _start(int newState, bool end){
	if((newState >= 2 && newState <= 4) || (end && newState == 0)){
		domain = temp;
		temp = "";
	}
}

void _domainOrPort(int newState, bool end){
	if(newState == 7){
		scheme = temp;
		temp = "";
	}else if(newState == 5){
		char pport = temp[temp.length()-1];
		domain = temp.substr(0, temp.length()-1);
		temp = pport;
	}
}

void _path(int newState, bool end){
	if(newState == 4 || newState == 3 || (end && newState == 2)){
		path = temp;
		temp = "";
	}
}

void _queryString(int newState, bool end){
	if(newState == 4 || (end && newState == 3)){
		queryString = temp;
		temp = "";
	}
}

void _fragmentId(int newState, bool end){
	if(end && newState == 4){
		fragmentId = temp;
		temp = "";
	}
}

void _port(int newState, bool end){
	if(newState == 2 || (end && newState == 5)){
		port = temp;
		temp = "";
	}
}

void _domain(int newState, bool end){
	if(newState == 2 || newState == 5 || (end && newState == 6)){
		domain = temp;
		temp = "";
	}
}

void section(int state, int newState, bool end){
	switch(state){
		case 0: _start(newState, end);break;
		case 1: _domainOrPort(newState, end);break;
		case 2: _path(newState, end);break;
		case 3: _queryString(newState, end);break;
		case 4: _fragmentId(newState, end); break;
		case 5: _port(newState, end); break;
		case 6: _domain(newState, end);break;
	}
}

void printResult(int state){
	if(state == -1 || state == 1 || state == 7)
		cout << "invalid input url" << endl;
	else{
		cout << "scheme:" << scheme << endl;
		cout << "domain:" << domain << endl;
		cout << "port:" << port << endl; 
		cout << "path:" << path << endl;
		cout << "queryString:" << queryString << endl;
		cout << "fragmentId:" << fragmentId << endl << endl;
	}
}

int getInput(int state, string line, int i){
	int input;
	switch(line[i]){
		case ':': input = 1;break;
		case '/': 
			input = 2;
			if(state == 2)
				temp = temp+line[i];
			break;
		case '?': input = 3;break;
		case '#': input = 4;break;
		default: 
			input = 0;
			temp = temp+line[i];
			break;
	}
	return input;
}

void parseURL(string line){
	int i = 0;
	int state = 0;
	while(i < line.length()){
		int input = getInput(state, line, i);
		int newState = stateMachine[state][input];
		section(state, newState, i == line.length()-1);
		state = newState;
		i++;

		if(state == -1)
			break;
	}
	printResult(state);
}

int main(int argc, char** argv){
	string line = "";
	while(getline(cin, line)){
		scheme = "", domain = "", port = "", path = "", queryString = "", fragmentId = "", temp = "";
		parseURL(line);
	}
}