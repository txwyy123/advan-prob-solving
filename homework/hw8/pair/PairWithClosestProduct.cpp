#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void getInput(int &count, vector<int> &nums, int &target){
	cout << "count of numbers:";
	cin >> count;

	cout << "the numbers:";
	int i = 0;
	while(i < count){
		int num;
		cin >> num;
		nums.push_back(num);
		i++;
	}

	cout << "the target:";
	cin >> target;
}

int findMiddle(int count, vector<int> &nums){
	int middle = count;
	for(int i = 0; i < count; i++){
		if(nums[i] >= 0){
			middle = i;
			break;
		}
	}
	return middle;
}

void doGet(vector<int> &nums, int l, int r, int target, int &prod, int &pair1, int &pair2, bool negative){
	while(l < r){
		if(abs(nums[l]*nums[r]-target) < abs(prod-target)){
			prod = nums[l]*nums[r];
			pair1 = nums[l];
			pair2 = nums[r];
		}else if(nums[l]*nums[r]>target){
			if(negative)
				l++;
			else
				r--;
		}else{
			if(negative)
				r--;
			else
				l++;
		}
	}
}

void getClosestPair(vector<int> &nums, int count, int target, int &pair1, int &pair2){
	//sort the numbers
	sort(nums.begin(), nums.end());

	//find the first non-negative number
	int middle = findMiddle(count, nums);
	int prod = nums[0]*nums[1];

	//iterate over the negative part
	if(0 < middle-1)
		doGet(nums, 0, middle-1, target, prod, pair1, pair2, true);

	//iterate over the left part
	if(middle < count)
		doGet(nums, middle, count-1, target, prod, pair1, pair2, false);
}

int main(){
	//input
	int count, target;
	vector<int> nums;
	getInput(count, nums, target);

	int pair1 = nums[0], pair2 = nums[1];
	getClosestPair(nums, count, target, pair1, pair2);

	//output
	cout << "the closest pair is " << pair1 << " and " << pair2 << endl;

}