#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
//./A.exe < in.txt
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> sets;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        vector<int> conj(c, 0);
        for (auto &num: conj) cin >> num;
        sets.push_back(conj);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int cobertura = 0;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < sets[i].size(); j++) {
                    cobertura |= (1 << (sets[i][j] - 1));
                }
            }
        }

        if (cobertura == (1 << n) - 1) ans++;
    }   
    cout << ans;
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