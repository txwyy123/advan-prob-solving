#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int len;
	cin >> len;
	char *a = new char[len];
	for(int i = 0; i < len; i++)
		cin >> a[i];

	int r = 0, g = 0, b = 0;
	for(int i = 0; i < len; i++){
		switch(a[i]){
			case 'R':r++;break;
			case 'G':g++;break;
			case 'B':b++;break;
		}
	}

	for(int i = 0; i < len; i++){
		if(i < r)
			a[i] = 'R';
		else if(i < r+g)
			a[i] = 'G';
		else
			a[i] = 'B';
	}


	for(int i = 0; i < len; i++)
		cout << a[i] << " ";

	delete [] a;
}