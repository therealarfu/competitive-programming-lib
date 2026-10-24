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
bool vis[MAXN] = {0};

void dfs(int s) {
    vis[s] = true;
    for (auto it: adj[s]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

void solve() {

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