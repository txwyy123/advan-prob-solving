#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int money = 255;
	int changes[4] = {10,10,10,10};
	int values[4] = {1, 5, 10, 25};
	int dp[5][money+1];

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < money+1; j++)
			dp[i][j] = -1;

	for(int i = 1; i < 5; i++){
		for(int j = 0; j <= changes[i-1]; j++){
			dp[i-1][0] = 0;
			for(int k = 0; k < money+1; k++){
				dp[i][k] = max(dp[i][k], dp[i-1][k]);
				if(k >= j*values[i-1] && dp[i-1][k-j*values[i-1]] != -1)
					dp[i][k] = max(dp[i][k], dp[i-1][k-j*values[i-1]]+j);
			}
		}
	}

	cout<<"input:"<<endl<<changes[0]<<"p "<<changes[1]<<"n "<<changes[2]<<"d "<<changes[3]<<"q "<<money<<endl;
	cout<<"output:"<<endl<<"the maximum number of coins is "<<dp[4][money]<<endl;
}
