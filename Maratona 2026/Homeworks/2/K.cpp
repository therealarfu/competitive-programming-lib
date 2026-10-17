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
    int n, t; cin >> n >> t;
    vi arr(n, 0); for (auto &num: arr) cin >> num;
    ll soma = 0;
    int ans = 0;
    int count = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
        count++;
        if (soma > t) {
            while (soma > t) {
                soma -= arr[l];
                count--;
                l++;
            } 
        }
        ans = max(ans, count);
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