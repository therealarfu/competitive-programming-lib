#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pli = pair<ll,int>;

// Adiciona aresta não direcionada u-v na lista de adjacência.
void addEdge(vvi &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Adiciona aresta direcionada u-v na lista de adjacência.
void addDirectedEdge(vvi &adj, int u, int v) {
    adj[u].push_back(v);
}

// Adiciona aresta ponderada não direcionada no formato {peso, vizinho}.
void addWeightedEdge(vector<vector<pli>> &adj, int u, int v, ll w) {
    adj[u].push_back({w,v});
    adj[v].push_back({w,u});
}

// Adiciona aresta ponderada direcionada no formato {peso, vizinho}.
void addDirectedWeightedEdge(vector<vector<pli>> &adj, int u, int v, ll w) {
    adj[u].push_back({w,v});
}

// Verifica se (r,c) está dentro do grid; retorna bool.
bool valid(int r, int c, int rows, int cols) {
    return r>=0 && r<rows && c>=0 && c<cols;
}
