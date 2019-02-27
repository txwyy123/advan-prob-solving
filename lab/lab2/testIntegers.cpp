#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void skipSpace(char* str, int &index){
	while(str[index] == ' ')
		index++;
}

int getSign(char* str, int &index){
	if(str[index] == '+'){
		index++;
		return 1;
	}else if(str[index] == '-'){
		index++;
		return -1;
	}
	return 1;
}

int getNum(char* str, int &index, int sign){
	int num = 0;
	while(str[index] != '\0'){
		char c = str[index];
		if(c < '0' || c > '9')
			break;
		//in case of overflow
		else if(num > 214748364 || (num == 214748364 && c > '7'))
			return sign == 1 ? 2147483647 : -2147483648;
		else
			num = num*10+c-'0';
		index++;
	}
	return num;
}

int atoi(char* str){
	int sign = 1;
	int num = 0;
	int index = 0;

	skipSpace(str, index);
	sign = getSign(str, index);
	num = getNum(str, index, sign);
	return num*sign;
}

int getSign(int &i){
	if(i < 0){
		i = -i;
		return -1;
	}
	return 1;
}

void getStr(char* str, int &index, int base, int &i){
	do{
		str[index++] = i%base+'0';
	} while ((i = i/base)>0);
}

void reverse(char* str, int index){
	int l = 0, r = index-1;
	while(l < r){
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
		l++;r--;
	}
}

int itoa(int i, char* str, int base){
	if(base != 2 && base != 8 && base != 10 && base != 16)
		return 1;//not supported base

	int index = 0;
	int sign = getSign(i);
	getStr(str, index, base, i);
	
	if(sign < 0)
		str[index++] = '-';
	str[index] = '\0';

	reverse(str, index);

	return 0;
}

int main(int argc, char** argv){
	string str;
	while(cin >> str){
		printf("original string:%s\n", str.c_str());

		char s[100];
		itoa(atoi(str.c_str()), s, 10);
		printf("string after conversion:%s\n", s);

		if(strcmp(str.c_str(), s) != 0){
			printf("the two strings don't equal\n");
		}

		printf("\n");
	}
}