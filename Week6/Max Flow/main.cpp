//Problem: Max Flow
//Description
//Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
//Input
//•Line 1: two positive integers N and M (1 <= N <= 10
//4
//, 1 <= M <= 10
//6
//)
//•Line 2: contains 2 positive integers s and t
//•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
//th
// arc
//Output
//  Write the value of the max-flow found
//Example
//Input
//7 12
//6 7
//1 7 7
//2 3 6
//2 5 6
//3 1 6
//3 7 11
//4 1 7
//4 2 4
//4 5 5
//5 1 4
//5 3 4
//6 2 8
//6 4 10
//Output
//17



#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define V 10001

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = s;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (parent[v] == -1 && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                if (v == t) return true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    vector<vector<int>> rGraph(V, vector<int>(V));
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    vector<int> parent(V);
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int maxFlow = fordFulkerson(graph, s, t);
    cout << maxFlow << endl;

    return 0;
}
