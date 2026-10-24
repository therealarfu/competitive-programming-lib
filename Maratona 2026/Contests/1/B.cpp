
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

set<int> ans;
string s;

void dfs(int pos, int cur, bool skipped, int missing, int first) {
    if (cur > 99999) return;

    if (pos == (int)s.size()) {
        if (skipped) {
            ans.insert(missing);
        } else {
            if (cur <= 99999) ans.insert(cur);

            if (first > 1) ans.insert(first - 1);
        }
        return;
    }

    string num = to_string(cur);

    if (s.compare(pos, num.size(), num) == 0) {
        dfs(pos + num.size(), cur + 1,
            skipped, missing, first);
    }

    if (!skipped) {
        dfs(pos, cur + 1, true, cur, first);
    }
}

void solve() {
    cin >> s;
    ans.clear();

    for (int len = 1; len <= min(5, (int)s.size()); len++) {
        int first = stoi(s.substr(0, len));

        dfs(len, first + 1, false, -1, first);
    }

    cout << ans.size() << endl;

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
