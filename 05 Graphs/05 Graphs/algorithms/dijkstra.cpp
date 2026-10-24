#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1e18+7;
#define FORi1 for(int i=1;i<=n;i++)
void dijkstra_pq() {
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pair<ll,int>>> adj(n+1);
    for (int i=0;i<m;i++) {
        int u, v;cin >> u >> v;
        ll w;cin>>w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<ll> dist(n+1, LINF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        if (dis > dist[node]) continue;
        for (auto [w, v]:adj[node]) {
            if (dis + w < dist[v]) {
                dist[v] = dis+w;
                pq.push({dist[v], v});
            }
        }
    }
    FORi1 {
        if (dist[i] == LINF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;

};

void dijkstra_set() {
    int n, m, s; cin >> n >> m >> s;
    vector<vector<pair<ll,int>>> adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<ll> dist(n+1, LINF);
    set<pair<ll,int>> st;
    dist[s] = 0;
    st.insert({0, s});
    while (!st.empty()) {
        auto [dis, node] = *st.begin();
        st.erase(st.begin());
        for (auto [w, v] : adj[node]) {
            if (dis + w < dist[v]) {
                if (dist[v] != LINF) {
                    st.erase({dist[v], v});
                }
                dist[v] = dis + w;
                st.insert({dist[v], v});
            }
        }
    }

    FORi1 {
        if (dist[i] == LINF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

void dijkstra_states() {
    int n, m, src, dst, k;
    cin >> n >> m >> src >> dst >> k;
    vector<vector<pair<ll,int>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    vector<vector<ll>> dist(n, vector<ll>(k+2, LINF));
    queue<tuple<int, int, ll>> q;
    dist[src][0] = 0;
    q.push({0, src, 0});
    while (!q.empty()) {
        auto [stops, node, cost] = q.front();
        q.pop();
        if (cost > dist[node][stops]) continue;
        if (stops == k+1) continue;
        for (auto [w, v] : adj[node]) {
            if (cost + w < dist[v][stops+1]) {
                dist[v][stops+1] = cost + w;
                q.push({stops+1, v, dist[v][stops+1]});
            }
        }
    }
    ll ans = LINF;
    for (int i=0; i<=k+1; i++) {
        ans = min(ans, dist[dst][i]);
    }
    if (ans == LINF) cout << -1 << endl;
    else cout << ans << endl;
}
