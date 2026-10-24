/*
Rotten Oranges
*/
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m,0));
    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }
    queue<pair<pair<int,int>,int>> q;
    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j] == 2) {
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    int mx_tm = 0;
    vector<int> dr = {-1, +1, 0, 0};
	vector<int> dc = {0, 0, +1, -1};
    while (!q.empty()) {
        auto [r, c] = q.front().first;
        int tm = q.front().second;
        q.pop();
        mx_tm = max(mx_tm, tm);
        for (int i=0; i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                vis[nr][nc] = 2;
                q.push({{nr, nc}, tm+1});
        }
        }
    }
    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            if (vis[i][j] != 2 && grid[i][j] == 1) {
                cout << -1;
                return;
            }
        }
    }
    cout << mx_tm;
    
}
/*
Rotten Oranges
*/
int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
    queue<pair<pair<int,int>,int>> q;

    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            if (grid[i][j] == 2) {
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
        }
    }

    int mx_tm = 0;
    vector<int> dr = {-1, +1, 0, 0};
    vector<int> dc = {0, 0, +1, -1};

    while (!q.empty()) {
        auto [r, c] = q.front().first;
        int tm = q.front().second;
        q.pop();

        mx_tm = max(mx_tm, tm);

        for (int i=0; i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            if (vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                vis[nr][nc] = 2;
                q.push({{nr, nc}, tm+1});
            }
        }
    }

    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            if (vis[i][j] != 2 && grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return mx_tm;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i=0; i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }

    cout << bfs(grid, vis, n, m) << endl;
}