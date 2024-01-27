////Problem: Minimum Spanning Tree - Kruskal
////Description
////Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
////Input
////Line 1: N and M (1≤N,M≤10
////5
////) in which NN is the number of nodes and MM is the number of edges.
////Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
////Output
////Write the weight of the minimum spanning tree found.
////Example
////Input
////5 8
////1 2 1
////1 3 4
////1 5 1
////2 4 2
////2 5 1
////3 4 3
////3 5 3
////4 5 2
////Output
////7
//
//#include "bits/stdc++.h"
//using namespace std;
//struct Edge {
//    int u,v,w;
//    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){};
//};
//
////DSU
//
//vector<int> par;
//
//void init(int n){
//    par.resize(n+1,0);
//    for(int i=1;i<=n;i++) par[i] = i;
//}
//
//int find(int u){
//    if(par[u] == u) return u;
//    else return find(par[u]);
//}
//
//bool join(int u,int v){
//    u = find(u);
//    v = find(v);
//    if(u==v) return false;
//
//    par[v] = u;
//    return true;
//}
//int n,m;
//vector<Edge> edges;
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> n>>m;
//
//   // init(n);
//    par.resize(n+1,0);
//    for(int i=1;i<=n;i++) par[i] = i;
//
//    for(int i=1;i<=m;i++){
//        int u,v,w;
//        cin>>u>>v>>w;
//        edges.push_back({u,v,w});
//    }
//
//    sort(edges.begin(),edges.end(),[](Edge e1,Edge e2)
//         {return e1.w <= e2.w;});
//
//    int total = 0;
//
//    for(auto e : edges){
//        if(join(e.u,e.v)){
//            total += e.w;
//        }
//    }
//
//    cout << total;
//
//
//return 0;
//}


