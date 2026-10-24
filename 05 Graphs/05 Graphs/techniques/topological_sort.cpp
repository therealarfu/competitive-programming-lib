/*
DFS 0 indexed - STACK
*/

void dfs(int node, vi &vis, stack<int> &st, vvi &adj) {
    vis[node] =1;
    for (auto v:adj[node]) {
        if (!vis[v]) dfs(v , vis, st, adj);
    }
    st.push(node);
}

    int n, m; cin >> n >> m;
    vvi adj(n);
    for (int i=0; i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); 
    }

    vi vis(n, 0);
    stack<int> st;
    FORi0 {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vi ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for (auto x:ans) cout << x << " ";

/*
Kahn's Algorithm - BFS 0 indexed
*/
   int n, m; cin >> n >> m;
    vvi adj(n);
    for (int i=0; i<m;i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); 
    }
    vi indegree(n,0);
    FORi0 {
        for (auto v:adj[i]) indegree[v]++;
    }
    queue<int> q;
    FORi0 if (indegree[i] == 0) q.push(i);
    vi topological_sort;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topological_sort.push_back(node);
        for (auto v:adj[node]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    for (auto x:topological_sort) cout << x << " ";
    
// Alien Dictionary - Topological Sort

int n, k; cin >> n >> k;
vs dic(n);
FORi0 cin >> dic[i];

vvi adj(k);
bool possible = true;

for (int i=0; i<n-1; i++) {
    string s1 = dic[i];
    string s2 = dic[i+1];

    int len = min(sz(s1), sz(s2));
    bool found = false;

    for (int j=0; j<len; j++) {
        if (s1[j] != s2[j]) {
            adj[s1[j] - 'a'].pb(s2[j] - 'a');
            found = true;
            break;
        }
    }

    if (!found && sz(s1) > sz(s2)) {
        possible = false;
    }
}

vi indegree(k, 0);

for (int i=0; i<k; i++) {
    for (auto v:adj[i]) indegree[v]++;
}

queue<int> q;

for (int i=0; i<k; i++) {
    if (indegree[i] == 0) q.push(i);
}

vi topological_sort;

while (!q.empty()) {
    int node = q.front();
    q.pop();

    topological_sort.pb(node);

    for (auto v:adj[node]) {
        indegree[v]--;
        if (indegree[v] == 0) q.push(v);
    }
}

if (!possible || sz(topological_sort) != k) {
    cout << "IMPOSSIBLE";
    return;
}

string ans = "";

for (auto x:topological_sort) {
    ans += char(x + 'a');
}

cout << ans;


// Find Eventual Safe States 0i
vvi adj(n);
vvi adj_rev(n);
vi indegree(n,0);
FORi0 {
    for (auto v:adj[i]) {
        adj_rev[v].pb(i);
        indegree[i]++;
    }
}
queue<int> q;
vi safe_nodes;
FORi0 {
    if (indegree[i] == 0) q.push(i)
}
while (!q.empty()) {
    int node = q.front();
    q.pop();
    safe_nodes.pb(node);
    for (auto v:adj_rev[node]) {
        indegree[v]--;
        if (indegree[v] == 0) q.push(v);
    }
}

sort(all(safe_nodes));