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
const int MAXN = 2e5+5;
vector<int> adj[MAXN];
bool vis[MAXN] {false};

class Solution {
public:
    void bfs(int s, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<int> q;
        q.push(s);
        vis[s] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it: adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n+1, false);
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                bfs(i, adj, vis);
            }
        }
        return ans;
    }
};