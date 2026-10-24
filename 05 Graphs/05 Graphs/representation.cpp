#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pli = pair<ll,int>;

// Lê m arestas 1-indexadas não direcionadas; retorna lista de adjacência.
vvi readUndirectedGraph(int n, int m) {
    vvi adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

// Lê m arestas 1-indexadas direcionadas; retorna lista de adjacência.
vvi readDirectedGraph(int n, int m) {
    vvi adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    return adj;
}

// Lê m arestas ponderadas não direcionadas; retorna adj[u] = {peso, vizinho}.
vector<vector<pli>> readWeightedGraph(int n, int m) {
    vector<vector<pli>> adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    return adj;
}

// Lê m arestas não direcionadas; retorna matriz de adjacência 1-indexada.
vvi readAdjacencyMatrix(int n, int m) {
    vvi adj(n+1, vi(n+1, 0));
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    return adj;
}
