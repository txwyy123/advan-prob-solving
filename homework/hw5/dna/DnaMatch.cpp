#include <stdio.h>
#include <string>
#include <iostream>

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
				dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
		}
	}

	string s1_r;
	string s2_r;
	int i = s1.length()-1, j = s2.length()-1;
	while(i >= 0 && j >= 0){
		if(s1[i] == s2[j]){
			s1_r = s1[i--] + s1_r;
			s2_r = s2[j--] + s2_r;
		} else if(dp[i+1][j] < dp[i][j+1]){
			s1_r = '_' + s1_r;	
			s2_r = s2[j--] + s2_r;
		} else {
			s1_r = s1[i--] + s1_r;	
			s2_r = '_' + s2_r;
		}
	}

	while(i >= 0)
		s1_r = s1[i--] + s1_r;
	while(j >= 0)
		s2_r = s2[j--] + s2_r;

	cout<<"output:"<<endl<<"s1="<<s1_r<<endl<<"s2="<<s2_r<<endl;
}