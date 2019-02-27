#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	cout<<"input:"<<endl;

	string s1;
	string s2;
	cout << "s1=";
	cin >> s1;
	cout << "s2=";
	cin >> s2;

	int dp[s1.length()+1][s2.length()+1];

	for(int i = 0; i < s1.length()+1; i++)
		dp[i][0] = i;
	for(int j = 0; j < s2.length()+1; j++)
		dp[0][j] = j;

	for(int i = 1; i < s1.length()+1; i++){
		for(int j = 1; j < s2.length()+1; j++){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
		}
	}

	cout<<"output:"<<endl<<"the minimum number of edits is "<<dp[s1.length()][s2.length()]<<endl;
}