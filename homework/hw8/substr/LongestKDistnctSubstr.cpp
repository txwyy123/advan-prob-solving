#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void getInput(string &s, int &k){
	cout << "string: ";
	cin >> s;

	cout << "K: ";
	cin >> k;
}

int main(){
	string s;
	int k;
	getInput(s, k);

	int indexes[128] = {0};
	set<char> set;
	int start = 0, maxStart = 0, maxLen = 0;
	string result = "";
	for(int i = 0; i < s.length(); i++){
		indexes[s[i]] = i;
		if(set.size() == k && set.find(s[i]) == set.end()){
			int minIndex = i;
			char minChar;
			for(std::set<char>::iterator iter = set.begin(); iter != set.end(); ++iter){
				if(indexes[*iter] < minIndex){
					minIndex = indexes[*iter];
					minChar = *iter;
				}
			}
			set.erase(minChar);
			start = minIndex+1;
		}
		if(i-start+1 > maxLen){
			maxStart = start;
			maxLen = i-start+1;
		}
		set.insert(s[i]);
	}

	result = s.substr(maxStart, maxLen);
	cout << "the longest substring: " << result << endl;
}