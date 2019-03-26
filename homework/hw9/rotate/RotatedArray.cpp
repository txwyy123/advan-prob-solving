#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int len;
	cin >> len;
	int *a = new int[len];
	for(int i = 0; i < len; i++)
		cin >> a[i];
	int target;
	cin >> target;
	int l = 0, r = 5, m = (l+r)/2;
	while(l <= r){
		if(a[m] == target)
			break;
		else if(a[m] < target){
			if(a[l] < a[r] || target <= a[r])
				l = m+1;
			else
				r = m-1;
		}else{
			if(a[l] < a[r] || target >= a[l])
				r = m-1;
			else
				l = m+1;
		}
		m = (l+r)/2;
	}
	cout << m << endl;

	delete [] a;
}