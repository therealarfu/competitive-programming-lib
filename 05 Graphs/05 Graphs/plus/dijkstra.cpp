#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll,int>;
using vll = vector<ll>;
const ll LINF = 1e18+7;

// Calcula distâncias a partir de s em grafo ponderado sem pesos negativos; retorna vetor.
vll dijkstra_pq(int s, const vector<vector<pli>> &adj) {
    int n = adj.size();
    vll dist(n, LINF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[s] = 0;
    pq.push({0,s});
    while (!pq.empty()) {
        auto [dis,u] = pq.top();
        pq.pop();
        if (dis > dist[u]) continue;
        for (auto [w,v] : adj[u]) {
            if (dis+w < dist[v]) {
                dist[v] = dis+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
