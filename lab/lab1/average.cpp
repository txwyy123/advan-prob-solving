#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool checkParams(int argc){
	if(argc < 2){
		cout << "wrong number of parameters";
		return false;
	}
	return true;
}

bool isNum(string str)
{
    stringstream ss(str);
    double d;
    return (ss >> d) ? true : false;
}

void getAvgAndCount(double & average, double & count, string filename){
	ifstream fin(filename.c_str());  
    string s;
    while(getline(fin,s)){
        if(isNum(s)){
            average = atof(s.c_str())/(count+1)+average/(count+1)*count;
            count++;
        }
    }
}

int main(int argc, char **argv){
	if(!checkParams(argc))
		return 1;

    for(int i = 1; i < argc; i++){
        double average = 0.0;
        double count = 0.0;
        getAvgAndCount(average, count, argv[i]);
        cout << "The average of the "<<count<<" numbers in file "<<argv[i]<<" is "<<average<<endl;
    }
}