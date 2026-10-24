#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> roots;

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int u) {
    queue<int> q;

    q.push(u);
    vis[u] = true;
  
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            roots.push_back(i);
            bfs(i);
        }
    }

    cout << roots.size() - 1 << '\n';
    for (int i = 1; i < roots.size(); i++) {
        cout << roots[0] << ' ' << roots[i] << '\n';
    }

}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}