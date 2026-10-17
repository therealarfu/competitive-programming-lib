# Modelos de Grafos em C++ — Competição

> Todos os códigos assumem o seu template (`ll`, `vi`, `LINF`, etc.). Vértices indexados de **1 a n** (como nos slides), exceto os de grid (0-indexado).

## 0. Qual algoritmo usar?

| O problema pede... | Use | Complexidade |
|---|---|---|
| Alcançabilidade, componentes, ciclos | DFS / DSU | O(V+E) |
| Menor caminho, arestas sem peso | BFS | O(V+E) |
| Menor caminho, pesos 0 e 1 | 0-1 BFS | O(V+E) |
| Menor caminho, pesos ≥ 0 | Dijkstra | O((V+E) log V) |
| Pesos negativos / ciclo negativo | Bellman-Ford | O(VE) |
| Todos os pares (n ≤ 500) | Floyd-Warshall | O(V³) |
| Árvore geradora mínima | Kruskal + DSU | O(E log E) |
| Ordenação com dependências / DAG | Toposort (Kahn) | O(V+E) |
| Grupos mutuamente alcançáveis (dirigido) | SCC (Kosaraju) | O(V+E) |
| Pontes / pontos de articulação | Tarjan (low-link) | O(V+E) |
| Ancestral comum / distância em árvore | LCA (binary lifting) | O(log V) por query |
| Emparelhamento bipartido | Kuhn | O(VE) |
| Fluxo máximo / corte mínimo | Dinic | ~O(V²E) |

**Dicas:** use `ll` para distâncias; reinicialize arrays a cada caso de teste; se tiver ≥ 2e5 vértices em cadeia, DFS recursiva pode estourar a pilha (prefira BFS/iterativo quando der).

---

## 1. Template (corrigido)

Seu `#define endl '\n';` tem um `;` no final. Isso quebra coisas como `if (x) cout << endl; else ...`. Versão corrigida:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

void solve() {

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
```

---

## 2. Seus modelos transcritos (dos slides)

### 2.1 Matriz de adjacências (sem peso)

```cpp
const int MAXN = 1e3 + 5;
bool adj[MAXN][MAXN];

void add_edge(int u, int v) {
    adj[u][v] = 1;
    // adj[v][u] = 1;   // descomente se não direcionado
}

void remove_edge(int u, int v) {
    adj[u][v] = 0;
    // adj[v][u] = 0;
}
```

### 2.2 Matriz de adjacências (com peso)

```cpp
const int MAXN = 1e3 + 5;
const ll INF = 1e18;   // cuidado: conflita com o INF (int) do template, renomeie se precisar
int n;
ll adj[MAXN][MAXN];

void init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = INF;
}

void add_edge(int u, int v, ll w) {
    adj[u][v] = w;
    // adj[v][u] = w;
}

void remove_edge(int u, int v, ll w) {
    adj[u][v] = INF;
    // adj[v][u] = INF;
}
```

> No slide o `INF` é `ll`. No seu template `INF` é `int` e já existe `LINF`. Na prática, use `LINF` no lugar.

### 2.3 Lista de adjacências (sem peso)

```cpp
const int MAXN = 2e5 + 5;
int n, m;
vector<int> adj[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
```

### 2.4 Lista de adjacências (com peso)

```cpp
const int MAXN = 2e5 + 5;
int n, m;
vector<pair<int, ll>> adj[MAXN];

void add_edge(int u, int v, ll w) {
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});
}
```

### 2.5 DFS

```cpp
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v])
        dfs(v);
}
// Complexidade: O(V + E)
```

### 2.6 BFS

```cpp
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int s) {
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
// Complexidade: O(V + E)
```

### 2.7 BFS em grid

```cpp
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

const int MAXN = 1e3 + 5;
int n, m;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];

bool valid(int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; }

void bfs(int si, int sj) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[si][sj] = 0;
    q.push({si, sj});

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (valid(ni, nj) and dist[ni][nj] == -1 and grid[ni][nj] != '#') {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
}
```

### 2.8 Bicoloridade (grafo bipartido)

```cpp
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int color[MAXN]; // -1 = não visitado, 0/1 = cores

bool dfs(int u) {
    for (int v : adj[u]) {
        if (color[v] == -1) {
            color[v] = !color[u];
            if (!dfs(v)) return false;
        }
        else if (color[v] == color[u]) return false;
    }
    return true;
}
```

Como usar (grafo pode ter vários componentes):

```cpp
memset(color, -1, sizeof(color));
bool ok = true;
for (int u = 1; u <= n; u++) if (color[u] == -1) {
    color[u] = 0;
    if (!dfs(u)) ok = false;
}
// ok = true  => bipartido; color[u] já é a coloração
```

### 2.9 Ordenação topológica (Kahn)

```cpp
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int indeg[MAXN];
int n;

vector<int> toposort() {
    memset(indeg, 0, sizeof(indeg));
    vector<int> ord;

    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            indeg[v]++;

    queue<int> q;
    for (int u = 1; u <= n; u++)
        if (indeg[u] == 0)
            q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    // Se ord.size() < n, existe um ciclo e não há ordenação topológica
    return ord;
}
```

### 2.10 Encontrar ciclos (grafo não direcionado)

```cpp
const int MAXN = 2e5;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> cycle;

// -1: nenhum ciclo encontrado
// -2: ciclo encontrado e já completamente reconstruído
// >= 0: vértice onde o ciclo começou

int dfs(int u, int p) {
    if (vis[u]) return u;
    vis[u] = true;

    for (int v : adj[u]) if (v != p) {
        int ret = dfs(v, u);

        if (ret == -2) return -2;
        if (ret != -1) {
            cycle.push_back(u);
            if (u == ret) return -2;
            else return ret;
        }
    }

    return -1;
}
```

Como usar (`cycle` fica com os vértices do ciclo):

```cpp
for (int u = 1; u <= n; u++) if (!vis[u]) {
    if (dfs(u, 0) == -2) break;   // achou: cycle está preenchido
}
if (cycle.empty()) cout << "IMPOSSIBLE" << endl;
else {
    cycle.push_back(cycle[0]);    // se o problema pede repetir o primeiro vértice
    cout << cycle.size() << endl;
    for (int x : cycle) cout << x << " ";
    cout << endl;
}
```

> Esse modelo não trata arestas paralelas (multi-arestas) como ciclo de tamanho 2. Se o problema permitir isso, use o modelo com `edge id` da seção de pontes.

### 2.11 Componentes conexos & Flood Fill

```cpp
const int MAXN = 2e5 + 5;
int n;
vector<int> adj[MAXN];
int comp[MAXN];

void dfs(int u, int c) {
    comp[u] = c;
    for (int v : adj[u]) if (comp[v] == -1)
        dfs(v, c);
}

void init() {
    memset(comp, -1, sizeof(comp));

    int num = 0;
    for (int u = 1; u <= n; u++)
        if (comp[u] == -1)
            dfs(u, num++);
}
// num = quantidade de componentes
```

---

## 3. Modelos novos (prontos para a competição)

### 3.1 Leitura de grafo (padrão)

```cpp
const int MAXN = 2e5 + 5;
int n, m;
vi adj[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // remova se for dirigido
    }
}
```

Com pesos:

```cpp
vector<pair<int, ll>> adj[MAXN];
// ...
int u, v; ll w;
cin >> u >> v >> w;
adj[u].push_back({v, w});
adj[v].push_back({u, w});
```

### 3.2 DSU (Union-Find)

Útil para: componentes dinâmicos, Kruskal, "conectar cidades", detectar ciclo ao adicionar aresta.

```cpp
struct DSU {
    vi p, sz;
    int comps;

    DSU(int n = 0) { init(n); }

    void init(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
        comps = n;
    }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        comps--;
        return true;
    }

    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
};
```

Uso: `DSU d(n); d.unite(a, b); d.same(a, b); d.comps;`

### 3.3 Caminho mínimo reconstruído (BFS)

Útil para: "imprima o caminho", labirintos em grafo, menor número de arestas.

```cpp
const int MAXN = 2e5 + 5;
int n;
vi adj[MAXN];
int dist[MAXN], par[MAXN];

vi bfs_path(int s, int t) {
    for (int i = 1; i <= n; i++) dist[i] = -1, par[i] = -1;
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            par[v] = u;
            q.push(v);
        }
    }

    if (dist[t] == -1) return {};          // sem caminho
    vi path;
    for (int v = t; v != -1; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}
```

### 3.4 BFS multi-fonte

Útil para: "distância até a fonte mais próxima" (monstros, incêndio, hospitais).

```cpp
// Adicione TODAS as fontes na fila com dist = 0 antes do loop
void multi_bfs(vi& sources) {
    for (int i = 1; i <= n; i++) dist[i] = -1;
    queue<int> q;
    for (int s : sources) {
        dist[s] = 0;
        q.push(s);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

### 3.5 Grid: labirinto com reconstrução do caminho (S → E)

Útil para: "imprima a sequência de movimentos" (CSES Labyrinth e similares).

```cpp
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& s : g) cin >> s;

    int si = 0, sj = 0, ei = 0, ej = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') si = i, sj = j;   // início
            if (g[i][j] == 'B') ei = i, ej = j;   // fim
        }

    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};
    const char mv[] = {'D', 'U', 'R', 'L'};

    vector<vi> dist(n, vi(m, -1));
    vector<vector<char>> from(n, vector<char>(m, 0));
    queue<pii> q;
    dist[si][sj] = 0;
    q.push({si, sj});

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if (g[ni][nj] == '#' || dist[ni][nj] != -1) continue;
            dist[ni][nj] = dist[i][j] + 1;
            from[ni][nj] = mv[k];
            q.push({ni, nj});
        }
    }

    if (dist[ei][ej] == -1) {
        cout << "NO" << endl;
        return;
    }

    string path;
    int i = ei, j = ej;
    while (i != si || j != sj) {
        char c = from[i][j];
        path += c;
        if (c == 'D') i--;
        else if (c == 'U') i++;
        else if (c == 'R') j--;
        else j++;
    }
    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}
```

### 3.6 Grid: contar "salas" / ilhas (Flood Fill)

Útil para: "quantas ilhas/salas/componentes", "maior área conectada".

```cpp
int n, m;
vector<string> g;
vector<vector<bool>> seen;

int fill_(int i, int j) {          // retorna o tamanho da região (BFS iterativo)
    int cnt = 0;
    queue<pii> q;
    seen[i][j] = true;
    q.push({i, j});
    const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cnt++;
        for (int k = 0; k < 4; k++) {
            int nx = x + di[k], ny = y + dj[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#' || seen[nx][ny]) continue;
            seen[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    for (auto& s : g) cin >> s;
    seen.assign(n, vector<bool>(m, false));

    int rooms = 0, best = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] != '#' && !seen[i][j]) {
                rooms++;
                best = max(best, fill_(i, j));
            }
    cout << rooms << " " << best << endl;
}
```

### 3.7 Dijkstra (com reconstrução de caminho)

Útil para: menor caminho com pesos ≥ 0 (o mais cobrado em competição).

```cpp
const int MAXN = 2e5 + 5;
int n, m;
vector<pair<int, ll>> adj[MAXN];
ll dist[MAXN];
int par[MAXN];

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) dist[i] = LINF, par[i] = -1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;          // entrada velha
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

vi get_path(int t) {
    if (dist[t] >= LINF) return {};
    vi path;
    for (int v = t; v != -1; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}
```

### 3.8 0-1 BFS

Útil para: pesos só 0 ou 1 (ex.: "quantas arestas preciso inverter").

```cpp
vector<pii> adj[MAXN];   // {destino, peso 0 ou 1}
int dist[MAXN];

void bfs01(int s) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    deque<int> dq;
    dist[s] = 0;
    dq.push_back(s);

    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}
```

### 3.9 Bellman-Ford (ciclo negativo)

Útil para: pesos negativos, "existe ciclo de peso negativo?", imprimir esse ciclo.

```cpp
struct Edge { int u, v; ll w; };
int n, m;
vector<Edge> edges;
ll dist[MAXN];
int par[MAXN];

// retorna um vértice dentro/alcançável de ciclo negativo, ou -1 se não existe
int bellman_ford(int s) {
    for (int i = 1; i <= n; i++) dist[i] = LINF, par[i] = -1;
    dist[s] = 0;
    int x = -1;
    for (int it = 0; it < n; it++) {
        x = -1;
        for (auto& e : edges) {
            if (dist[e.u] == LINF) continue;
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                par[e.v] = e.u;
                x = e.v;
            }
        }
        if (x == -1) return -1;     // convergiu: sem ciclo negativo
    }
    return x;                        // ainda relaxou na n-ésima vez: tem ciclo negativo
}

// Para recuperar o ciclo:
vi get_neg_cycle(int x) {
    for (int i = 0; i < n; i++) x = par[x];   // garante que x está DENTRO do ciclo
    vi cyc;
    for (int v = x;; v = par[v]) {
        cyc.push_back(v);
        if (v == x && cyc.size() > 1) break;
    }
    reverse(cyc.begin(), cyc.end());
    return cyc;
}
```

> Para detectar ciclo negativo em QUALQUER lugar do grafo (não só alcançável de `s`), inicialize `dist[i] = 0` para todos em vez de só `s`.

### 3.10 Floyd-Warshall

Útil para: todos os pares com n ≤ 500, queries de distância entre quaisquer dois vértices.

```cpp
const int MAXN = 505;
int n;
ll d[MAXN][MAXN];

void floyd() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = (i == j ? 0 : LINF);
    // leia as arestas: d[u][v] = min(d[u][v], w); (e d[v][u] se não dirigido)

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] < LINF && d[k][j] < LINF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
```

### 3.11 Kruskal (Árvore Geradora Mínima)

Útil para: "custo mínimo para conectar tudo", "estradas mínimas" (usa o DSU de 3.2).

```cpp
struct Edge {
    int u, v; ll w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges) cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll total = 0;
    for (auto& e : edges)
        if (dsu.unite(e.u, e.v))
            total += e.w;

    if (dsu.comps != 1) cout << "IMPOSSIBLE" << endl;   // grafo desconexo
    else cout << total << endl;
}
```

### 3.12 Detectar ciclo em grafo DIRIGIDO (com reconstrução)

Útil para: "existe ciclo?", "imprima um ciclo" (ex.: CSES Round Trip II).

```cpp
const int MAXN = 2e5 + 5;
int n;
vi adj[MAXN];
int state[MAXN];   // 0 = não visitado, 1 = na pilha, 2 = finalizado
int par[MAXN];
vi cyc;

bool dfs(int u) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 0) {
            par[v] = u;
            if (dfs(v)) return true;
        } else if (state[v] == 1) {      // aresta de retorno => ciclo v -> ... -> u -> v
            cyc.clear();
            for (int x = u; x != v; x = par[x]) cyc.push_back(x);
            cyc.push_back(v);
            reverse(cyc.begin(), cyc.end());
            return true;
        }
    }
    state[u] = 2;
    return false;
}

// uso:
// for (int u = 1; u <= n; u++) if (state[u] == 0 && dfs(u)) { /* cyc = v, ..., u */ break; }
```

### 3.13 DP em DAG usando toposort (caminho mais longo / contar caminhos)

Útil para: "maior caminho de 1 até n", "número de caminhos" (usa o `toposort()` de 2.9).

```cpp
// Maior caminho (em arestas) de 1 até n
void solve() {
    // ... ler grafo dirigido em adj, n
    vi ord = toposort();
    vi dp(n + 1, -INF), prv(n + 1, -1);
    dp[1] = 0;

    for (int u : ord) {
        if (dp[u] == -INF) continue;
        for (int v : adj[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                prv[v] = u;
            }
        }
    }

    if (dp[n] == -INF) { cout << "IMPOSSIBLE" << endl; return; }
    vi path;
    for (int v = n; v != -1; v = prv[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int x : path) cout << x << " ";
    cout << endl;
}
```

Contar caminhos de 1 até n (mod):

```cpp
const int MOD = 1e9 + 7;
vi cnt(n + 1, 0);
cnt[1] = 1;
for (int u : ord)
    for (int v : adj[u])
        cnt[v] = (cnt[v] + cnt[u]) % MOD;
// resposta: cnt[n]
```

### 3.14 SCC — Componentes Fortemente Conexos (Kosaraju)

Útil para: "cidades mutuamente alcançáveis", condensar o grafo em um DAG.

```cpp
const int MAXN = 2e5 + 5;
int n;
vi adj[MAXN], radj[MAXN];   // grafo e grafo reverso
bool vis[MAXN];
int comp[MAXN];
vi order;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : radj[u]) if (comp[v] == -1) dfs2(v, c);
}

int scc() {
    for (int u = 1; u <= n; u++) if (!vis[u]) dfs1(u);
    reverse(order.begin(), order.end());
    memset(comp, -1, sizeof(comp));
    int c = 0;
    for (int u : order) if (comp[u] == -1) dfs2(u, c++);
    return c;   // número de SCCs
}
// Ao ler cada aresta u->v: adj[u].push_back(v); radj[v].push_back(u);
// Os componentes saem numerados em ordem topológica (0 = componente "fonte").
```

Condensação (DAG de componentes):

```cpp
set<pii> cedges;
for (int u = 1; u <= n; u++)
    for (int v : adj[u])
        if (comp[u] != comp[v]) cedges.insert({comp[u], comp[v]});
```

### 3.15 Pontes e pontos de articulação

Útil para: "quais estradas, se removidas, desconectam o grafo", "quais cidades são críticas". Usa `edge id` para tratar arestas paralelas corretamente.

```cpp
const int MAXN = 2e5 + 5;
int n, m;
vector<pii> adj[MAXN];      // {vizinho, id da aresta}
int tin[MAXN], low[MAXN], timer_ = 0;
vector<pii> bridges;
bool is_cut[MAXN];

void dfs(int u, int pe) {   // pe = id da aresta que chegou em u
    tin[u] = low[u] = ++timer_;
    int children = 0;
    for (auto [v, id] : adj[u]) {
        if (id == pe) continue;
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) bridges.push_back({u, v});
            if (low[v] >= tin[u] && pe != -1) is_cut[u] = true;
            children++;
        }
    }
    if (pe == -1 && children > 1) is_cut[u] = true;
}

// Leitura: adj[u].push_back({v, i}); adj[v].push_back({u, i});  (i = 0..m-1)
// Chamada: for (int u = 1; u <= n; u++) if (!tin[u]) dfs(u, -1);
```

### 3.16 Árvores: pai, profundidade, tamanho de subárvore, diâmetro

```cpp
const int MAXN = 2e5 + 5;
int n;
vi adj[MAXN];
int par[MAXN], dep[MAXN], sub[MAXN];

void dfs(int u, int p) {
    par[u] = p;
    sub[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sub[u] += sub[v];
    }
}
// dfs(1, 0);   // raiz = 1
```

**Diâmetro da árvore** (2 BFS, usa o `bfs(s)` do slide 2.6 com `dist[]`):

```cpp
int farthest() {
    int best = 1;
    for (int i = 1; i <= n; i++) if (dist[i] > dist[best]) best = i;
    return best;
}

// bfs(1); int a = farthest();
// bfs(a); int b = farthest();
// diâmetro (em arestas) = dist[b]
```

### 3.17 LCA (Binary Lifting)

Útil para: ancestral comum, distância entre dois nós da árvore, k-ésimo ancestral.

```cpp
const int MAXN = 2e5 + 5;
const int LOG = 18;          // 2^18 > 2e5
int n;
vi adj[MAXN];
int up[MAXN][LOG], dep[MAXN];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int k = 1; k < LOG; k++) up[u][k] = up[up[u][k - 1]][k - 1];
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
// Chame dfs(1, 1): a raiz aponta para si mesma.

int kth(int u, int k) {      // k-ésimo ancestral
    for (int i = 0; i < LOG; i++) if (k >> i & 1) u = up[u][i];
    return u;
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    a = kth(a, dep[a] - dep[b]);
    if (a == b) return a;
    for (int k = LOG - 1; k >= 0; k--)
        if (up[a][k] != up[b][k])
            a = up[a][k], b = up[b][k];
    return up[a][0];
}

int tree_dist(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
```

### 3.18 Emparelhamento bipartido (Kuhn)

Útil para: atribuir tarefas a pessoas, "casais", máximo de pares (n ≤ ~1000).

```cpp
const int MAXN = 1005;
int nl, nr;                 // tamanho da esquerda e da direita
vi adj[MAXN];               // adj[u] = vértices da direita ligados a u (esquerda)
int matchR[MAXN];
bool used[MAXN];

bool try_kuhn(int u) {
    for (int v : adj[u]) {
        if (used[v]) continue;
        used[v] = true;
        if (matchR[v] == -1 || try_kuhn(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int max_matching() {
    memset(matchR, -1, sizeof(matchR));
    int res = 0;
    for (int u = 1; u <= nl; u++) {
        memset(used, false, sizeof(used));
        if (try_kuhn(u)) res++;
    }
    return res;
}
// Pares: para v em 1..nr, se matchR[v] != -1 então (matchR[v], v) está emparelhado.
```

### 3.19 Fluxo máximo (Dinic)

Útil para: fluxo máximo, corte mínimo, emparelhamento grande, caminhos disjuntos.

```cpp
struct Dinic {
    struct E { int to; ll cap; };
    vector<E> e;
    vector<vi> g;
    vi level, it;
    int n;

    Dinic(int n) : n(n), g(n + 1), level(n + 1), it(n + 1) {}

    void add_edge(int u, int v, ll c) {
        g[u].push_back(e.size()); e.push_back({v, c});
        g[v].push_back(e.size()); e.push_back({u, 0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int id : g[u]) {
                if (e[id].cap > 0 && level[e[id].to] == -1) {
                    level[e[id].to] = level[u] + 1;
                    q.push(e[id].to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int u, int t, ll f) {
        if (u == t) return f;
        for (int& i = it[u]; i < (int)g[u].size(); i++) {
            int id = g[u][i];
            int v = e[id].to;
            if (e[id].cap > 0 && level[v] == level[u] + 1) {
                ll got = dfs(v, t, min(f, e[id].cap));
                if (got > 0) {
                    e[id].cap -= got;
                    e[id ^ 1].cap += got;
                    return got;
                }
            }
        }
        return 0;
    }

    ll maxflow(int s, int t) {
        ll flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (ll f = dfs(s, t, LINF)) flow += f;
        }
        return flow;
    }
};

// Dinic d(n);  d.add_edge(u, v, cap);  ll ans = d.maxflow(s, t);
// Aresta não dirigida: d.add_edge(u, v, c); d.add_edge(v, u, c);
```

---

## 4. Checklist rápido na hora da prova

1. **Limites**: n, m até quanto? (2e5 → O(n log n); 500 → O(n³) ok; 1e3 grid → BFS ok)
2. **Dirigido ou não?** Lembre de `adj[v].push_back(u)` no não dirigido.
3. **Pesos**: `ll` para distâncias; `LINF` como infinito.
4. **Vários casos de teste**: limpe `adj`, `vis`, `dist`, `comp` etc. a cada caso (não use `memset` em array gigante se `t` for grande — limpe só até `n`).
5. **Grafo desconexo?** Faça o loop `for (u = 1..n) if (!vis[u])`.
6. **Arestas paralelas / laços?** Pense se o modelo trata.
7. **Saída**: se precisa imprimir caminho/ciclo, guarde `par[]`.
