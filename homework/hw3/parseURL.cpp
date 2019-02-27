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

void section(int state, int newState, bool end){
	switch(state){
		case 0:
			if((newState >= 2 && newState <= 4) || (end && newState == 0)){
				domain = temp;
				temp = "";
			}
			break;
		case 1:
			if(newState == 7){
				scheme = temp;
				temp = "";
			}else if(newState == 5){
				char pport = temp[temp.length()-1];
				domain = temp.substr(0, temp.length()-1);
				temp = pport;
			}
			break;
		case 2:
			if(newState == 4 || newState == 3 || (end && newState == 2)){
				path = temp;
				temp = "";
			}
			break;
		case 3:
			if(newState == 4 || (end && newState == 3)){
				queryString = temp;
				temp = "";
			}
			break;
		case 4:
			if(end && newState == 4){
				fragmentId = temp;
				temp = "";
			}
			break;
		case 5:
			if(newState == 2 || (end && newState == 5)){
				port = temp;
				temp = "";
			}
			break;
		case 6:
			if(newState == 2 || newState == 5 || (end && newState == 6)){
				domain = temp;
				temp = "";
			}
			break;
	}
}

void parseURL(string line){
	int i = 0;
	int state = 0;
	while(i < line.length()){
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
		int newState = stateMachine[state][input];
		section(state, newState, i == line.length()-1);
		state = newState;
		i++;

		if(state == -1)
			break;
	}
	if(state == -1 || state == 1 || state == 7)
		cout << "invalid input url" << endl;
	else{
		cout << "scheme:" << scheme << endl;
		cout << "domain:" << domain << endl;
		cout << "port:" << port << endl; 
		cout << "path:" << path << endl;
		cout << "queryString:" << queryString << endl;
		cout << "fragmentId:" << fragmentId << endl;
	}
}

int main(int argc, char** argv){
	string line = "";
	while(getline(cin, line)){
		scheme = "", domain = "", port = "", path = "", queryString = "", fragmentId = "", temp = "";
		parseURL(line);
	}
}