#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[]) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int d, int& maxD, int& maxNode, vector<int> adj[], vector<bool>& visited) {
    visited[node] = 1;
    if(d > maxD) {
        maxD = d;
        maxNode = node;
    }
    for(int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if(visited[child] == 0) {
            dfs(child, d + 1, maxD, maxNode, adj, visited);
        }
    }
}

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n];
    for(int i = 0; i < n; i++) {
        if(A[i] == -1) 
            continue;
        addEdge(i, A[i], adj);
    }
    int maxD = -1, maxNode = 0;
    vector<bool> visited(n, false);
    dfs(0, 0, maxD, maxNode, adj, visited);
    fill(visited.begin(), visited.end(), false);
    maxD = -1;
    dfs(maxNode, 0, maxD, maxNode, adj, visited);
    return maxD;
}