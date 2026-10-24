#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

// Calcula distâncias mínimas a partir de (sr,sc) em grid de '#' e células livres; retorna matriz.
vvi gridBFS(const vector<string> &grid, int sr, int sc) {
    int n = grid.size(), m = grid[0].size();
    vvi dist(n, vi(m, -1));
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    queue<pii> q;
    dist[sr][sc] = 0;
    q.push({sr,sc});
    while (!q.empty()) {
        auto [r,c] = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int nr = r+dr[i], nc = c+dc[i];
            if (nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if (grid[nr][nc] == '#' || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c]+1;
            q.push({nr,nc});
        }
    }
    return dist;
}
