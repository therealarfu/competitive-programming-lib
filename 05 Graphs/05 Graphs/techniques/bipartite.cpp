/*
1. IS BIPARTITE?
*/
bool bfs(int start, vvi &adj, vi &color) {
    color[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto v: adj[node]) {
            if (color[v] == -1) {
                color[v] = !color[node];
                q.push(v);
            } else if (color[v] == color[node]) return false;
        }
    }
    return true;
}

int main() {
    fastio;
    int n, m; cin >> n >> m;
    vvi adj(n);
    for (int i=0; i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi color(n,-1);
    for (int i=0; i<n;i++) {
        if (color[i] == -1) {
            if (bfs(i, adj, color) == false) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}