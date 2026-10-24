// Detect a cycle in an undirected graph - 0 indexed
bool dfs(int node, int parent, vvi &adj, vi &vis) {
    vis[node] = 1;
    for (auto v:adj[node]) {
        if (!vis[v]) {
            if (dfs(v, node, adj, vis) == true) return true;
        } else if (v != parent) return true;
    }
    return false;
}

bool solve() {
    int n, m; cin >> n >> m;
    vvi adj(n);
    for (int i=0; i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi vis(n, 0);
    for (int i=0; i<n;i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis) == true) return true;
        }
    }
    return false;
}
// Detect a cycle in an undirected graph - 1 indexed
bool dfs(int node, int parent, vvi &adj, vi &vis) {
    vis[node] = 1;
    for (auto v:adj[node]) {
        if (!vis[v]) {
            if (dfs(v, node, adj, vis) == true) return true;
        } else if (v != parent) return true;
    }
    return false;
}

bool solve() {
    int n, m; cin >> n >> m;
    vvi adj(n+1);
    for (int i=0; i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); 
        adj[v].pb(u);
    }

    vi vis(n+1, 0);
    for (int i=1; i<=n;i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis) == true) return true;
        }
    }
    return false;
}