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
    string alf; cin >> alf;
    vector<string> valf;
    for (char c: alf) valf.push_back(string(1, c));       
    sort(valf.begin(), valf.end());

    vector<string> permutations;
    do {
        string temp = "";
        for (string e: valf) temp += e;
        permutations.push_back(temp);
    } while (next_permutation(valf.begin(), valf.end()));

    cout << permutations.size() << '\n';
    for (auto &text: permutations) cout << text << '\n';
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