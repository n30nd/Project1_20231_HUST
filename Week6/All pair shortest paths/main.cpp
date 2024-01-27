//Problem: All pair shortest paths
//Description
//Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
//Input
//Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
//Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
//Output
//Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
//Example
//Input
//4 9
//1 2 9
//1 3 7
//1 4 2
//2 1 1
//2 4 5
//3 4 6
//3 2 2
//4 1 5
//4 2 8
//Output
//0 9 7 2
//1 0 8 3
//3 2 0 5
//5 8 12 0

#include "bits/stdc++.h"
using namespace std;
#define MAX 10001
int n,m;
int d[MAX][MAX];

void floyWs(){
    for(int k=0;k<n;k++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(d[u][k] != INT_MAX && d[k][v] != INT_MAX){
                    d[u][v] = min(d[u][k] + d[k][v],d[u][v]);
                }
            }
        }
    }
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n>>m;


        for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<n;i++) d[i][i] = 0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u-1][v-1] = w;
    }

    floyWs();

    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            cout << d[u][v] <<" ";
        }
        cout << "\n";
    }



    return 0;
    }
