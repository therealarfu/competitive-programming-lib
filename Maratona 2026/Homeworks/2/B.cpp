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

bool is_initial_board_valid(int (&table)[9][9]) {
    for (int i = 0; i < 9; i++) {
        map<int, int> freq_line;
        map<int, int> freq_col; 
        for (int j = 0; j < 9; j++) {
            if (table[j][i] != 0) {
                freq_line[table[j][i]]++;
                if (freq_line[table[j][i]] > 1) return false;
            }
            if (table[i][j] != 0) {
                freq_col[table[i][j]]++;
                if (freq_col[table[i][j]] > 1) return false;
            }

            if (i % 3 == 0 && j % 3 == 0) {
                map<int, int> freq_grid; 
                for (int k = 0; k < 9; k++) {
                    if (table[i + k / 3][j + k % 3] != 0) {
                        freq_grid[table[i + k / 3][j + k % 3]]++;
                        if (freq_grid[table[i + k / 3][j + k % 3]] > 1) return false;
                    }
                    
                }
            }

        }
    }
    return true;
}

bool is_valid(int (&table)[9][9], int value, int line, int col) {
    int start_line = (line / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = 0; i < 9; i++) {
        if (table[line][i] == value || table[i][col] == value || table[start_line + i / 3][start_col + i % 3] == value){
            return false;
        }
    }
    return true;
}

bool grid_complete(int (&table)[9][9]) {
    for (int i = 0; i < 81; i++) {
        if (table[i / 9][i % 9] == 0) {
            return false;
        }
    }
    return true;
}

bool dfs (int (&table)[9][9], int pos) {
    if (pos >= 81) return grid_complete(table);

    int line = pos / 9;
    int col = pos % 9;

    if (table[line][col] != 0) {
        return dfs(table, pos + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (is_valid(table, i, line, col)) {
                table[line][col] = i;
                if (dfs(table, pos + 1)) return true;
                table[line][col] = 0;
            } 
        }
    }
    return false;
}

void solve() {
    int table[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> table[i][j];
        }
    }

    if (!is_initial_board_valid(table)) {
        cout << "No solution" << '\n';
        return;
    }

    if (dfs(table, 0)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << table[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "No solution" << '\n';
    }
}

int main() {
    fastio;
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}