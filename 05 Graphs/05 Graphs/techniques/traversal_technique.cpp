/*
CONNECTED COMPONENTS - MULTIPLE CONNECTED COMPONENTS IN A GRAPH
1. Traversal Algorithm - vis arr method
*/
int n, m; cin >> n >> m;
int vis[n+1];
vector<vector<int>> adj(n+1);
for (int i=0; i<m;i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
for (int i = 1; i<n; i++) {
    if (!vis[i]) traversal(i);
}
/*
BFS - BREADTH FIRST SEARCH: LEVEL WISE
1. Print the traversal of the graph - 0index
    - space O(n)
    - time O(n+m)
*/
int n, m; cin >> n >> m;
vector<vector<int>> adj(n);
for (int i=0; i < m;i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int> vis(n,0);
vis[0] = 1;
queue<int> q;
q.push(0);
vector<int> bfs;
while (!q.empty()) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto v: adj[node]) {
        if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
}
for (auto x:bfs) cout << x << " ";
cout << endl;

/*
DFS - DEPTH FIRST SEARCH: RECURSION
1. Print the traversal of the graph - 0index
    - space O(n)
    - time O(n+m)
*/
void dfs(int node,const vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans) {
    vis[node] = 1;
    ans.push_back(node);
    //traverse all its nb
    for (auto v: adj[node]) {
        if (!vis[v]) dfs(v, adj, vis, ans);
    } 
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n);
    vector<int> ans;
    for (int i=0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start=0;
    dfs(start, adj, vis, ans);
    for (auto x: ans) cout << x << " ";
    cout << endl;
}

