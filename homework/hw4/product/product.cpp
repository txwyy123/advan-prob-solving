#include "stdio.h"
#include "iostream"
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calProduct(vector<int> nums){
	vector<int> result;
	if(nums.size() <= 1)
		return result;

	vector<int> left;
	vector<int> right;

	for_each(nums.begin(), nums.end(), [&](int num){left.push_back(left.empty() ? num : num*left.back());});
	for_each(nums.rbegin(), nums.rend(), [&](int num){right.push_back(right.empty() ? num : num*right.back());});

	vector<int>::iterator iL = left.begin();
	vector<int>::reverse_iterator iR = right.rbegin();
	for(; iL != left.end(); ++iL, ++iR)
		result.push_back(iL == left.begin() ? *(iR+1) : (iL == left.end()-1 ? *(iL-1) : (*(iR+1))*(*(iL-1))));
	return result;
}

void getNums(vector<int> &nums){
	int num;
	char c;
	cout << "please input the array for test:" << endl;
    while((c=getchar())!='\n'){
        if(c != ' '){
            ungetc(c,stdin);
            cin>>num;
            nums.push_back(num);
        }
    }
}

void printRes(vector<int> result){
    cout << "the result is:" << endl;
	for_each(result.begin(), result.end(), [](int num){cout << num << " ";});
	cout << endl;
}

int main(){
	vector<int> nums;
	getNums(nums);
    printRes(calProduct(nums));
}