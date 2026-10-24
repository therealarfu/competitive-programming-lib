// Counting Rooms
void bfs(int n, int m, int i, int j, vector<vector<char>> &grid, vector<vector<char>> &vis) {
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        //up
        if (i != 0 && vis[i-1][j] == 0 && grid[i-1][j] == '.') {
            vis[i-1][j] = 1;
            q.push({i-1, j});
        }
        //right
        if (j != m-1 && vis[i][j+1] == 0 &&grid[i][j+1] == '.') {
            vis[i][j+1] = 1;
            q.push({i,j+1});
        }
        //left
        if (j != 0 && vis[i][j-1] == 0 &&grid[i][j-1] == '.') {
            vis[i][j-1] = 1;
            q.push({i, j-1});
        }
        //down
        if (i != n-1 &&vis[i+1][j] == 0 && grid[i+1][j] == '.') {
            vis[i+1][j] = 1;
            q.push({i+1, j});
        }
    }
}
 

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m, 0));
	vector<vector<char>> vis(n, vector<char>(m,0));
	int icount = 0;
	FOR2D(i, j, n, m) cin >> grid[i][j];
	FOR2D(i, j, n, m) {
		if (!vis[i][j] && grid[i][j] == '.') {
					icount++;
					bfs(n, m, i, j, grid, vis);
			}
	}
	cout << icount;
}

// Number of Islands
/*
Number Of Islands 
*/
void bfs(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis) {
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        //up
        if (i != 0 && vis[i-1][j] == 0 && grid[i-1][j] == 1) {
            vis[i-1][j] = 1;
            q.push({i-1, j});
        }
        //right
        if (j != m-1 && vis[i][j+1] == 0 &&grid[i][j+1] == 1) {
            vis[i][j+1] = 1;
            q.push({i,j+1});
        }
        //left
        if (j != 0 && vis[i][j-1] == 0 &&grid[i][j-1] == 1) {
            vis[i][j-1] = 1;
            q.push({i, j-1});
        }
        //down
        if (i != n-1 &&vis[i+1][j] == 0 && grid[i+1][j] == 1) {
            vis[i+1][j] = 1;
            q.push({i+1, j});
        }
        //d1
        if (i != 0 && j != 0 &&vis[i-1][j-1] == 0 && grid[i-1][j-1] == 1) {
            vis[i-1][j-1] = 1;
            q.push({i-1, j-1});
        }
        //d2
        if (i != n-1 && j != m-1 && vis[i+1][j+1] == 0 &&grid[i+1][j+1] == 1) {
            vis[i+1][j+1] = 1;
            q.push({i+1, j+1});
        }
        //d3
        if (i != 0 && j != m-1 && vis[i-1][j+1] == 0 &&grid[i-1][j+1] == 1) {
            vis[i-1][j+1] =1;
            q.push({i-1, j+1});
        }
        //d4
        if (i != n-1 && j != 0 &&vis[i+1][j-1] == 0 && grid[i+1][j-1] == 1) {
            vis[i+1][j-1] =1;
            q.push({i+1, j-1});
        }
    }
}
 
int n, m; cin >> n >> m;
vector<vector<int>> grid(n, vector<int>(m, 0));
vector<vector<int>> vis(n, vector<int>(m,0));
int icount = 0;
for (int i=0; i<n;i++) {
    for (int j=0;j<m;j++) {
        cin >> grid[i][j];
    }
}
for (int i=0; i<n;i++) {
    for (int j=0;j<m;j++) {
        if (!vis[i][j] && grid[i][j] == 1) {
            icount++;
            bfs(n, m, i, j, grid, vis);
        }
    }
}
cout << icount;


#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define FORi0 for(int i=0;i<n;i++)
#define FORbt for (int i=start;i<n;i++)
#define FORr0 for(int r=0;r<n;r++)
#define FORi1 for(int i=1;i<=n;i++)
#define FORj0 for(int j=0;j<n;j++)
#define FORj1 for(int j=1;j<=n;j++)
#define FOR2D(i, j, rows, cols) for(int i=0;i<rows;i++) for(int j =0;j<cols;j++)
#define MAT(name, rows, cols, val) vvi name(rows, vi(cols, val))
#define PRINT_ARR(v) { for(auto &x : v) cout << x << " "; cout << endl; }
#define PRINT_MAT(m) { for(auto &row : m) { for(auto &x : row) cout << x << " "; cout << endl; } }
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

vector<int> dr = {-1, +1, 0, 0};
vector<int> dc = {0, 0, +1, -1};


void bfs(int r, int c, int n, int m, vvi &grid, vvi &vis, int &sum) {
	queue<pii> q;
	q.push({r, c});
	sum += grid[r][c];
	vis[r][c] =1;
	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >=n || nc < 0 || nc >= m) continue;
			if (!vis[nr][nc] && grid[nr][nc] >0) {
				q.push({nr, nc});
				vis[nr][nc] = 1;
				sum += grid[nr][nc];
			}
		}
	}	
}

void solve() {
	int n,m;cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<vector<int>> vis(n, vector<int>(m,0));
	int mx_sum = 0;
	FOR2D(i,j,n,m) cin >> grid[i][j];
	FOR2D(i,j,n,m) {
		if (grid[i][j] > 0) {
			int sum = 0;
			bfs(i, j, n, m, grid, vis, sum);
			mx_sum = max(mx_sum, sum);
		}
	}
	cout << mx_sum << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) {
    	solve();
	}
	return 0;
}
