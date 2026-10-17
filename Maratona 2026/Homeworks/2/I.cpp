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
    ll n, cows; cin >> n >> cows;
    vll arr(n, 0); for (auto &num: arr) cin >> num;
    sort(arr.begin(), arr.end());

    ll l = 1;
    ll r = arr[arr.size()-1];
    ll ans = l;

    auto is_possible = [&](ll d) {
        ll last = arr[0];
        ll count = 1;
        for (ll i = 1; i < n; i++) {
            if (arr[i] - last >= d) {
                last = arr[i];
                count++;
                if (count >= cows) return true;
            }
        }
        return count >= cows;
    };

    while (l <= r) {
        ll m = l + (r-l)/2;

        if (!is_possible(m)) {
            r = m - 1;
        } else {
            ans = m;
            l = m + 1;  
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    ll t = 1; cin >> t;
    while (t--) {
    solve();
    }
    return 0;
}