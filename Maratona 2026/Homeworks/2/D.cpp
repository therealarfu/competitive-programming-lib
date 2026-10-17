#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

// sweep line
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> arr(n, {0, 0}); for (auto &x: arr) cin >> x.first >> x.second; 

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({arr[i].first, 1});
    }

    for (int i = 0; i < n; i++) {
        events.push_back({arr[i].second, -1});
    }

    sort(events.begin(), events.end(), [](auto &x, auto &y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first < y.first;
    });

    int ans = 0;
    int count = 0;

    for (int i = 0; i < 2 * n; i++) {
        count += events[i].second;
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