#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

// Percorre os vértices alcançáveis a partir de start; retorna ordem de visita.
vi bfsTraversal(int start, const vvi &adj) {
    vi vis(adj.size(), 0), ans;
    queue<int> q;
    vis[start] = 1;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return ans;
}

// Conta componentes de células 1 conectadas em oito direções; retorna quantidade.
int countGridComponents8(const vvi &grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vvi vis(n, vi(m, 0));
    const int dr[8] = {-1,-1,-1,0,0,1,1,1};
    const int dc[8] = {-1,0,1,-1,1,-1,0,1};
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] != 1 || vis[i][j]) continue;
            ans++;
            queue<pii> q;
            q.push({i,j});
            vis[i][j] = 1;
            while (!q.empty()) {
                auto [r,c] = q.front();
                q.pop();
                for (int d=0; d<8; d++) {
                    int nr = r+dr[d], nc = c+dc[d];
                    if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
                    if (grid[nr][nc] != 1 || vis[nr][nc]) continue;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    return ans;
}

// Expande simultaneamente de todas as células 2 para as células 1; retorna tempo ou -1.
int multiSourceGridTime(vvi grid) {
    int n = grid.size(), m = grid[0].size();
    const int dr[4] = {-1,1,0,0};
    const int dc[4] = {0,0,-1,1};
    queue<tuple<int,int,int>> q;
    for (int r=0; r<n; r++) {
        for (int c=0; c<m; c++) {
            if (grid[r][c] == 2) q.push({r,c,0});
        }
    }
    int ans = 0;
    while (!q.empty()) {
        auto [r,c,t] = q.front();
        q.pop();
        ans = max(ans,t);
        for (int d=0; d<4; d++) {
            int nr=r+dr[d], nc=c+dc[d];
            if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if (grid[nr][nc] != 1) continue;
            grid[nr][nc] = 2;
            q.push({nr,nc,t+1});
        }
    }
    for (auto &row : grid) for (int x : row) if (x == 1) return -1;
    return ans;
}

// Calcula distâncias a partir de start; retorna -1 para inalcançáveis.
vector<int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}

// Calcula a distância mínima entre start e target; retorna -1 se não há caminho.
int shortestPath(
    int start,
    int target,
    const vector<vector<int>>& adj
) {
    int n = adj.size();

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == target)
            return dist[u];

        for (int v : adj[u]) {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return -1;
}

// Calcula distâncias em grid com paredes '#'; retorna matriz.
vector<vector<int>> bfsGrid(
    int sr,
    int sc,
    const vector<string>& grid
) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(
        n,
        vector<int>(m, -1)
    );

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n ||
                nc < 0 || nc >= m)
                continue;

            if (grid[nr][nc] == '#')
                continue;

            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return dist;
}

// Reconstrói caminho mínimo start→target; retorna vetor de vértices.
vector<int> bfsPath(
    int start,
    int target,
    const vector<vector<int>>& adj
) {
    int n = adj.size();

    vector<int> dist(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            parent[v] = u;

            q.push(v);
        }
    }

    if (dist[target] == -1)
        return {};

    vector<int> path;

    for (int cur = target;
         cur != -1;
         cur = parent[cur]) {

        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    return path;
}

// Calcula menor número de operações n→m com -1 ou *2; retorna distância.
int bfsImplicit(int n, int m) {
    int limit = 2*max(n,m)+2;
    vector<int> dist(limit, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == m)
            return dist[x];

        if (x - 1 >= 0 &&
            dist[x - 1] == -1) {

            dist[x - 1] = dist[x] + 1;
            q.push(x - 1);
        }

        if (2 * x < limit &&
            dist[2 * x] == -1) {

            dist[2 * x] = dist[x] + 1;
            q.push(2 * x);
        }
    }

    return -1;
}
