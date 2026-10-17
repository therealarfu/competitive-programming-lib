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
    int n; cin >> n;
    vi arr(n, 0); for (auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int count = 0;
    int l = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] - arr[l] > 5) {
            while (arr[i] - arr[l] > 5) {
                l++;
                count--;
            }
        }
        ans = max(ans, count);
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