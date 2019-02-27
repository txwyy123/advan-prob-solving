#include <stdio.h>
#include <iostream>
#include <climits>
#include <vector>
#include <memory>

using namespace std;

int getMinPath(int start, int n){
	//construct graph
	vector<vector<int> > graph(n+1,vector<int>(n+1));
	for(int i = 1; i <= n; i++){
		if(i+1 <= n)
			graph[i][i+1] = 1;
		if(3*i <= n)
			graph[i][3*i] = 1;
	}

	//initialize dist and pre
	int *dist = new int[n];
	int *pre = new int[n];
	int *visited = new int[n];
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
		pre[i] = -1;
		visited[i] = 0;
	}
	dist[start-1] = 0;

	for(int i = 0; i < n; i++){
		//find the closest vertice to the vertices whose distance has been decided
		int min = INT_MAX;
		int minV = -1;
		for(int j = 0; j < n; j++){
			if(visited[j] == 0 && dist[j] <= min){
				min = dist[j];
				minV = j;
			}
		}
		visited[minV] = 1;

		//iterate over all it's neighbors to update the shortest path
		for(int j = 1; j < n+1; j++){
			if(graph[minV+1][j] == 1){
				if(dist[minV]+1 < dist[j-1]){
					dist[j-1] = dist[minV]+1;
					pre[j-1] = minV;
				}
			}
		}
	}

	int result = dist[n-1];
	for(int i = 0; i < n+1; i++){
		graph[i].clear();
		graph[i].shrink_to_fit();
	}
	graph.clear();
	graph.shrink_to_fit();
	delete [] dist;
	delete [] pre;
	delete [] visited;
	return result;
}

int main(){
	cout << "input:" << endl;
	int test_count;
	cin >> test_count;
	int tests[test_count];
	for(int i = 0; i < test_count; i++)
		cin >> tests[i];
	
	cout << "output:" << endl;
	for(int i = 0; i < test_count; i++){
		int result = getMinPath(1, tests[i]);
		cout << result << endl;
	}
}