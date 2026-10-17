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
    ll n, l, r, x; cin >> n >> l >> r >> x;
    vll diff(n, 0); for (auto &num: diff) cin >> num;

    int ways = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        ll biggest = 0;
        ll smallest = INF;
        ll soma = 0;
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                counter++;
                soma += diff[i];
                biggest = max(biggest, diff[i]);
                smallest = min(smallest, diff[i]);
            }
        }
        
        if (counter >= 2 && biggest - smallest >= x && soma >= l && soma <= r) ways++;
    }
    cout << ways << '\n';
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