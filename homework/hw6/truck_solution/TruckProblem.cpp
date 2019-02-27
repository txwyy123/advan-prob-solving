#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int maxT;
int doGet(int n, int curP, int curT, int *time, int *position, int *value, bool *visited);

int doGet(int n, int curP, int curT, int *time, int *position, int *value, bool *visited){
    if(curT > maxT)
        return 0;

    int result = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i] && abs(curP-position[i])/100 <= time[i]-curT){
            visited[i] = true;
            int profit = value[i]+doGet(n, position[i], abs(curP-position[i])/100+curT, time, position, value, visited);
            if(profit > result) {
                result = profit;
            }
            visited[i] = false;
        }
    }
    return result;
}

int getMaxProfit(int n, int *time, int *position, int *value){
    bool *visited = new bool[n];
    maxT = time[n-1];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    int profit = doGet(n, 0, 0, time, position, value, visited);
    delete [] visited;
    return profit;
}


int main(){
    int n = 8;
    int *time = new int[n];
    int *position = new int[n];
    int *value = new int[n];

    cout << "input:" << endl;
    cout << "n:";
    cin >> n;
    cout << "time:";
    for(int i = 0; i < n; i++)
        cin >> time[i];
    cout << "position:";
    for(int i = 0; i < n; i++)
        cin >> position[i];
    cout << "value:";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout << "output:" << endl;
    cout << "Total Revenue:" << getMaxProfit(n, time, position, value) << endl;

    delete [] time;
    delete [] position;
    delete [] value;
}