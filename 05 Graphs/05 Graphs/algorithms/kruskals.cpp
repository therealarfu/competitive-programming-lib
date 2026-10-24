
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define endl "\n"
using ll = long long;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);

        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    int getSize(int node) {
        int pu = findUltimateParent(node);
        return size[pu];
    }
    bool sameComponent(int u, int v) {
        return findUltimateParent(u) == findUltimateParent(v);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<tuple<ll, int, int>> edges;
    for (int i=0; i<m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.pb({w, u, v});
    }
    sort(all(edges));
    DisjointSet ds(n);
    ll mst_w = 0;
    int cnt = 0;
    for (auto [w, u, v] : edges) {
        if (!ds.sameComponent(u, v)) {
            mst_w += w;
            ds.unionBySize(u, v);
            cnt++;
        }
    }
    if (cnt != n-1) cout << "IMPOSSIBLE" << endl;
    else cout << mst_w << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}
