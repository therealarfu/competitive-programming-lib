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
    int n, k; cin >> n >> k;
    int l = 1;
    int r = n;

    int ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if ((ll) m*(m+3)/2 > n + k) {
            r = m - 1;
        } else if ((ll) m*(m+3)/2 < n + k) {
            l = m + 1;
        } else {
            ans = n - m;
            break;
        }
    }
    cout << ans << '\n';
    return;
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