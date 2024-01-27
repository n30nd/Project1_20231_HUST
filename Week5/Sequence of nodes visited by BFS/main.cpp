//Problem: Sequence of nodes visited by BFS
//Description
//Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
//Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)
//
//Input
//Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
//Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge
//
//Output
//Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
//Example
//
//Input
//6 7
//2 4
//1 3
//3 4
//5 6
//1 2
//3 5
//2 3
//
//Output
//1 2 3 4 5 6

#include "bits/stdc++.h"
using namespace std;
#define MAX 1000

int n,m;
int visited[MAX];
vector<vector<int>> a;

void bfs(int u){
    if(visited[u]) return;

    queue<int> q;
    visited[u] = true;
    q.push(u);
    cout << u << " ";

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int v : a[t]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                cout << v << " ";
            }
        }
    }

}


int main(){
    cin >>n>>m;
    for(int i=1;i<=n;i++) visited[i] = false;
    a.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
    }

    for(int i=1;i<=n;i++) bfs(i);



return 0;
}
