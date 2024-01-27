    //Problem: Hamiton Cycle
    //Description
    //Given an undirected graph G = (V,E). Write a program to check if G is a Hamiltonian graph.
    //Input
    //Line 1: a positive integer T (number of graphs)
    //Subsequent lines are information about T graphs, each has the following format:
    //Line 1: n and m (number of nodes and edges)
    //Line i+1 (i = 1, 2, ..., m): u and v : two end points of the ith edge
    //Output
    //In the i
    //th
    // line, write 1 if the corresponding is a Hamiltonian graph, and write 0, otherwise
    //Example
    //Input
    //2
    //5 5
    //1 2
    //1 3
    //2 4
    //2 5
    //3 5
    //7 13
    //1 3
    //1 5
    //1 7
    //2 4
    //2 5
    //2 6
    //3 4
    //3 5
    //3 7
    //4 6
    //4 7
    //5 7
    //6 7
    //
    //Output
    //0
    //1

    #include "bits/stdc++.h"
    using namespace std;
    vector<vector<int>> g;
     int n,m;
     vector<int> path;
    vector<bool> visited;
    bool isPossible(int v,int pos){
        if(visited[v]) return false;
        if(g[path[pos-1]][v] != 1) return false;
        return true;
        }

    bool TRY(int pos){
        for(int v=1;v<n;v++){
            if(isPossible(v,pos)){
                visited[v] = true;
                path[pos] = v;
                if(pos == n-1){
                    if(g[v][0] == 1) return true;

                }
                else if (TRY(pos+1)) return true;
                visited[v] = false;
                path[pos] = -1;

            }
        }

        return false;
        }



    int main(){
        int t;
        cin>>t;
        for(int i=0;i<t;i++){

            cin>>n>>m;
            g.resize(n, vector<int>(n,0));
            visited.resize(n,false);
            path.resize(n,-1);
            for(int i=0;i<m;i++){
                int u,v;
                cin >> u>>v;
                g[u-1][v-1] = 1;
                g[v-1][u-1] = 1;
            }

            path[0] = 0;
            visited[0] = true;

            if(TRY(1)) cout << "1" <<endl;
            else cout << "0" <<endl;


            g.clear();
            visited.clear();
            path.clear();
        }



        return 0;
        }
