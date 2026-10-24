#include <bits/stdc++.h>
using namespace std;
/*
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i=0;i<=n;i++) parent[i] = i;
    }
    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ultimate_parent_u = findUltimateParent(u);
        int ultimate_parent_v = findUltimateParent(v);
        if (ultimate_parent_u == ultimate_parent_v) return;
        if (rank[ultimate_parent_u] < rank[ultimate_parent_v]) parent[ultimate_parent_u] = ultimate_parent_v;
        else if (rank[ultimate_parent_v] < rank[ultimate_parent_u]) parent[ultimate_parent_v] = ultimate_parent_u;
        else {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ultimate_parent_u = findUltimateParent(u);
        int ultimate_parent_v = findUltimateParent(v);
        if (ultimate_parent_u == ultimate_parent_v) return;
        if (size[ultimate_parent_u] < size[ultimate_parent_v]) {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        } else {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};
*/

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
    int getSize(int node) {
        int pu = findUltimateParent(node);
        return size[pu];
    }
    bool sameComponent(int u, int v) {
        return findUltimateParent(u) == findUltimateParent(v);
    }
};

int main () {
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Same\n";
    else cout << "Not same\n";
    ds.unionBySize(3,7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Same\n";
    else cout << "Not same\n";
    return 0;
}