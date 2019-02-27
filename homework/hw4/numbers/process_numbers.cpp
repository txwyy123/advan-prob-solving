#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


void open_file(fstream &fs, char mode, string filename){
	switch(mode){
		case 'r': fs.open(filename.c_str(), ios_base::in);break;
		case 'w': fs.open(filename.c_str(), ios_base::out);break;
		default: break;
	}
}

void readNums(vector<int> &nums, string filename){
	fstream fs;
	open_file(fs, 'r', filename);
	copy(istream_iterator<int>(fs), istream_iterator<int>(), back_inserter(nums));
	fs.close();
}

void outputNums(vector<int> nums, string odd_output, string even_output){
	fstream odd_fs, even_fs;

	open_file(odd_fs, 'w', odd_output);
	open_file(even_fs, 'w', even_output);
	for_each(nums.begin(), nums.end(), [&](int num){num%2 == 0 ? even_fs << num << " " : odd_fs << num << " ";});
	odd_fs.close();
	even_fs.close();
}

int main(){
	string input = "rand_numbers.txt", odd_output = "odd.txt", even_output = "even.txt";
	vector<int> nums;

	readNums(nums, input);
	sort(nums.begin(), nums.end());
	outputNums(nums, odd_output, even_output);
}
