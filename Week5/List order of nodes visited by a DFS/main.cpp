//Problem: List order of nodes visited by a DFS
//Description
//Given a undirected graph =(V,E) in which V = {1,2,..,n} is the set of nodes. Write a program that visit nodes of G by a DFS (consider a lexicorgraphic order of nodes).
//Input
//Line 1: contains 2 integers n and m (1 <= n,m <= 100000)
//Line i+1: contains u and v which are two end-points of the ith edge
//
//Output
//Sequence of nodes visited by DFS
//Example
//Input
//7 12
//1 2
//1 3
//2 3
//2 4
//2 7
//3 5
//3 7
//4 5
//4 6
//4 7
//5 6
//5 7
//Output
//1 2 3 5 4 6 7


#include "bits/stdc++.h"
using namespace std;
#define MAX 100001

bool visited[MAX];
vector<vector<int>> a;
int n,m;

void dfs(int u){
    if(visited[u]) return;
    cout << u <<" ";
    visited[u] = true;
    for(auto v : a[u]){
        dfs(v);
    }
}

int main(){
    cin >>n >> m;
    a.resize(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i=0;i<=n;i++) visited[i] = false;

    dfs(1);


    return 0;
}
