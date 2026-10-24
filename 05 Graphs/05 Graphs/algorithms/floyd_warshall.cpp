#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);


void solve() {
    int n; cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> mat[i][j];

            if (mat[i][j] == -1) mat[i][j] = INF;
            if (i == j) mat[i][j] = 0;
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][k] == INF || mat[k][j] == INF) continue;

                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (mat[i][i] < 0) {
            cout << "Negative cycle" << endl;
            return;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (mat[i][j] == INF) mat[i][j] = -1;
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    solve();
    return 0;
}