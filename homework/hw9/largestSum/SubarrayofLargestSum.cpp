#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int len;
	cin >> len;
	int *a = new int[len];
	for(int i = 0; i < len; i++)
		cin >> a[i];

	int result = -1000000;
	int sum = 0;
	for(int i = 0; i < len; i++){
		if(sum >= 0)
			sum += a[i];
		else
			sum = a[i];
		result = max(sum, result);
	}

	cout << (result > 0 ? result : 0) << endl;
	
	delete [] a;
}