#include <stdio.h>
#include <iostream>
#include <climits>
#include <vector>
#include <memory.h>

using namespace std;

int getMSTWeight(vector<int> &test, int n){
	int graph[n][n];
	int weight = 0;
	bool visited[n];
	int keys[n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			graph[i][j] = INT_MAX;

	for(int i = 0; i < test.size();){
		graph[test[i]-1][test[i+1]-1] = test[i+2];
		graph[test[i+1]-1][test[i]-1] = test[i+2];
		i += 3;
	}

	for(int i = 0; i < n; i++){
		visited[i] = false;
		keys[i] = graph[0][i];
	}
	visited[0] = true;

	for(int i = 1; i < n; i++){
		int minNode = 0;
		int minKey = INT_MAX;
		for(int j = 0; j < n; j++){
			if(!visited[j] && keys[j] < minKey){
				minNode = j;
				minKey = keys[j];
			}
		}

		visited[minNode] = true;
		weight += minKey;

		for(int j = 0; j < n; j++){
			if(!visited[j] && graph[minNode][j] < keys[j])
				keys[j] = graph[minNode][j];
		}
	}

	return weight;
}

int main(){
	int testCount;
	cout << "input:" << endl;
	cin >> testCount;

	vector<int> *tests = new vector<int>[testCount];
	int nodeCount[testCount];
	for(int i = 0 ; i < testCount; i++){
		vector<int> test;
		int nodes, edges;
		cin >> nodes;
		cin >> edges;
		for(int j = 0; j < edges*3; j++){
			int n;
			cin >> n;
			test.push_back(n); 
		}
		tests[i] = test;
		nodeCount[i] = nodes;
	}

	cout << "output:" << endl;
	for(int i = 0; i < testCount; i++){
		int result = getMSTWeight(tests[i], nodeCount[i]);
		cout << result << endl;
	}

	for(int i = 0; i < testCount; i++){
		tests[i].clear();
		tests[i].shrink_to_fit();
	}
	delete [] tests;
}