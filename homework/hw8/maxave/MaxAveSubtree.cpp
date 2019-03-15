#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <iomanip>

using namespace std;

struct Node{
	int index;
	double ave;
	int count;

	Node(){
		index = -1;
		ave = INT_MIN;
		count = 0;
	}
};

int main(){
	int count;
	cout << "count of nodes:";
	cin >> count;

	int *tree = new int[count];
	cout << "the nodes:";
	for(int i = 0; i < count; i++)
		cin >> tree[i];

	Node *nodes = new Node[count];
	Node result;

	for(int i = count-1; i >= 0; i--){
		Node cur;
		double total = 0;
		if(2*i+1 < count){
			cur.count += nodes[2*i+1].count;
			total += nodes[2*i+1].count*nodes[2*i+1].ave;
		}
		if(2*i+2 < count){
			cur.count += nodes[2*i+2].count;
			total += nodes[2*i+2].count*nodes[2*i+2].ave;
		}

		cur.index = i;
		cur.count += 1;
		total += tree[i];
		cur.ave = total/cur.count;
		nodes[i] = cur;

		if(result.index == -1 || cur.ave > result.ave)
			result = cur;
	}

	cout << "the maximum average subtree is " << result.index << " and it has " << result.count << " nodes";

	delete []tree;
	delete []nodes;
}