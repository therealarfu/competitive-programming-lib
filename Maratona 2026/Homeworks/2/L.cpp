#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

void solve() {
    ll n, x; cin >> n >> x;
    vll arr(n, 0); for (auto &num: arr) cin >> num;
    map<ll, ll> seen; // complement, index

    for (ll i = 0; i < n; i++) {
        auto it = seen.find(x - arr[i]);
        if (it != seen.end()) {
            cout << it->second + 1 << ' ' << i+1;
            return;
        }
        seen[arr[i]] = i;
    }
    cout << "IMPOSSIBLE";
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