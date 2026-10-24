#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

// Marca toda a componente alcançável a partir de u; modifica vis.
void dfs(int u, const vvi &adj, vi &vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, adj, vis);
    }
}

// Conta componentes conexas de grafo não direcionado 1-indexado; retorna total.
int countComponentsDFS(int n, const vvi &adj) {
    vi vis(n+1, 0);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i, adj, vis);
        }
    }
    return ans;
}
