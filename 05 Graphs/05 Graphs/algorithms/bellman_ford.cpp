#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1e18+7;
#define FORi1 for(int i=1;i<=n;i++)
#define FORgp for(int i=0;i<m;i++)
void Bellman_ford() {
    int n, m, s; cin >> n >> m >> s;
    vector<tuple<ll, int, int>> edges;
    FORgp {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    vector<ll> dist(n+1, LINF);
    dist[s] = 0;
    for (int i=1; i<n; i++) {
        for (auto [w, u, v] : edges) {
            if (dist[u] != LINF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto [w, u, v] : edges) {
        if (dist[u] != LINF && dist[u] + w < dist[v]) {
            cout << "Negative cycle" << endl;
            return;
        }
    }
    FORi1 {
        if (dist[i] == LINF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}