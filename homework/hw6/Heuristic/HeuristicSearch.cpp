#define MAX 10000.0

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <string>
#include <stdlib.h>

using namespace std;

void getMinPath(vector<vector<int> > &graph, vector<vector<int> > &coords, int n, double *keys, int *pre, bool *visited, int isHeuristic, char start, char end, vector<int> &expanded){	
	double h[n];
	double g[n];
	for(int i = 0; i < n; i++){
		pre[i] = -1;
		visited[i] = false;
		keys[i] = MAX;
		g[i] = MAX;
		h[i] = sqrt(pow(coords[i][0]-coords[end-'A'][0], 2.0)+pow(coords[i][1]-coords[end-'A'][1], 2.0));
	}

	if(isHeuristic == 0){
		keys[start-'A'] = 0;
	}else{
		g[start-'A'] = 0;
		for(int i = 0; i < n; i++)
			keys[i] = g[i]+h[i];
	}

	for(int i = 0; i < n; i++){
		int minV = -1;
		double minKey = MAX;
		for(int j = 0; j < n; j++){
			if(!visited[j] && keys[j] < minKey){
				minV = j;
				minKey = keys[j];
			}
		}

		expanded.push_back(minV);
		if(minV == end-'A')
			return;

		visited[minV] = true;
		for(int j = 0; j < n; j++){
			if(!visited[j] && graph[minV][j] == 1){
				double len = sqrt(pow(coords[minV][0]-coords[j][0], 2.0)+pow(coords[minV][1]-coords[j][1], 2.0));
				if(isHeuristic == 0){
					if(len+minKey < keys[j]){
						keys[j] = len+minKey;
						pre[j] = minV;
					}
				}else{
					if(len+g[minV] < g[j]){
						g[j] = len+g[minV];
					}
					if(g[j]+h[j] < keys[j]){
						keys[j] = g[j]+h[j];
						pre[j] = minV;
					}
				}
			}
		}
	}
}

int main(int argc, char **argv){
	char start = argv[1][0];
	char end = argv[2][0];
	int isHeuristic = atoi(argv[3]);

	int n;
	cin >> n;

	vector<vector<int> > graph(n, vector<int>(n));
	vector<vector<int> > coords(n, vector<int>(2));
	for(int i = 0; i < n; i++){
		char vertice;
		cin >> vertice;
		cin >> coords[vertice-'A'][0];
		cin >> coords[vertice-'A'][1];

		char c = getchar();
		while((c = getchar()) != '\n')
			if(c != ' ')
				graph[i][c-'A'] = 1;
	}

	int pre[n];
	double keys[n];
	bool visited[n];
	vector<int> expanded;

	getMinPath(graph, coords, n, keys, pre, visited, isHeuristic, start, end, expanded);

	if(isHeuristic == 0)
		cout << "running with Dijkstra Algorithm" << endl;
	else
		cout << "running with A* Algorithm" << endl;

	cout << "expanding sequence:" << endl;
	for(int i = 0; i < expanded.size(); i++)
		cout << (char)(expanded[i]+'A') << (i == expanded.size()-1 ? "" : " ->");
	cout << endl;

	string path;
	int p = end-'A';
	path += end;
	while((p = pre[p]) != -1){
		path = " ->" + path;
		path = (char)(p+'A') + path;
	}
	cout << "shortest path:" << endl;
	cout << path << endl;

	for(int i = 0; i < n; i++){
		graph[i].clear();
		graph[i].shrink_to_fit();
		coords[i].clear();
		coords[i].shrink_to_fit();
	}
	graph.clear();
	graph.shrink_to_fit();
	coords.clear();
	coords.shrink_to_fit();
	expanded.clear();
	expanded.shrink_to_fit();
}