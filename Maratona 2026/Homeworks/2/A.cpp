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
    ll n, p; cin >> n >> p;
    vll arr(n, 0); 
    for (auto &w: arr) cin >> w;

    ll l, r, m;
    l = 0;
    r = LINF;
    while (l < r) {
        m = l + (r-l)/2;

        ll result = 0;
        for (int i = 0; i < n; i++){
            result += m / arr[i];
            if (result > p) break;
        }    

        if (result < p) {
            l = m+1;
        } else {
            r = m;
        }
    }

    cout << l;
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

