#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

// Partição de 2 subconjuntos O(2^n * n)
// Guloso não resolve

void solve() {
    int n; cin >> n;
    vi arr(n, 0);
    for (auto &num: arr) cin >> num;

    ll ans = INF;

    for (int mask = 0; mask < (1 << n); mask++) {
        ll g1 = 0;
        ll g2 = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                g2 += (ll) arr[i];
            } else {
                g1 += (ll) arr[i];
            }
        }
        ans = min(ans, abs(g1 - g2));
    }
    cout << ans << '\n';
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