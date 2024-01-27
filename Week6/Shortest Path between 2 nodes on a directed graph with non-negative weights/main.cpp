//Problem: Shortest Path between 2 nodes on a directed graph with non-negative weights
//Description
//Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
//Input
//Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
//Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
//Line m+2: contains two integers s and t
//Output
//Write the weight of the shortest path found or write -1 if no path from s to t was found
//Example
//Input
//5 7
//2 5 87
//1 2 97
//4 5 78
//3 1 72
//1 4 19
//2 3 63
//5 1 18
//1 5
//
//Output
//97

//#include "bits/stdc++.h"
//using namespace std;
//
//
//int w[100001][100001];
//int d[100001];
//int n,m;
//int s,t;
//vector<pair<int,int>>  edges;
//int main(){
//    cin >> n>>m;
//
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++) w[i][j] = INT_MAX;
//    }
//    for(int i=1;i<=m;i++){
//        int x,y,ww;
//        cin >> x>>y>>ww;
//        w[x][y] = ww;
//        edges.push_back({x,y});
//    }
//    cin >> s>> t;
//    for(int i=1;i<=n;i++) d[i] = w[s][i];
//    d[s] = 0;
//    for(int i=1;i<n;i++){
//        for(auto e : edges){
//                if(d[e.first] != INT_MAX)
//            d[e.second] = min(d[e.second], d[e.first]+w[e.first][e.second]);
//        }
//    }
//    if(d[t] != INT_MAX)    cout << d[t];
//    else cout << -1;
//
//    return 0;
//    }


#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u,v,w;
    Edge(int _u,int _v, int _w): u(_u), v(_v), w(_w){};
};

vector<Edge> edges;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin >> x>>y>>z;
        edges.push_back({x,y,z});
    }
    int s,t;
    cin >> s >>t;

    int d[n+1];
    for(int i=1;i<=n;i++) d[i] = INT_MAX;
    d[s] = 0;
    for(auto e : edges){
        if(e.u == s){
            d[e.v] = e.w;
        }
    }

    for(int i=1;i<n;i++){
        for(auto e : edges){
            if(d[e.u] != INT_MAX){
                d[e.v] = min(d[e.v],d[e.u]+e.w);
            }
        }
    }

    cout << d[t];
    return 0;
    }
