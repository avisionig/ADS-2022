#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> vis, in;
int del[500][500], vid;
vector<pair<int,int>> edges;
 
bool dfs(int u, bool flag) {
    vis[u] = in[u] = vid;
    bool ret = false;
    for (int v: adj[u]) {
        if (del[u][v] == vid)
            continue;
        if (flag) edges.emplace_back(u, v);
        if (vis[v] != vid)
            ret |= dfs(v, flag);
        else if (in[v])
            return true;
    }
    in[u] = 0;
    return ret;
}
 

 
int main() {
    int n, m;
    bool flag = true;
    cin>> n >> m;
    adj.resize(n);
    vis.resize(n);
    in.resize(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
    }
 
    ++vid;
    int i;
    for (i = 0; i < n; ++i) {
        if (vis[i] != vid) {
            if (dfs(i, flag))
                break;
            else edges.clear();
        }
    }
    if (i == n) {
        cout<< "YES";
        return 0;
    }
    flag = false;
    for (auto edge: edges) {
        ++vid;
        int u = edge.first,
                v = edge.second;
        del[u][v] = vid;
        bool cycle = false;
        for (int j = 0; j < n; ++j) {
            if (vis[j] != vid) {
                if (dfs(j, flag)) {
                    cycle = true;
                    break;
                }
            }
        }
        if (!cycle) {
            cout <<"YES";
            return 0;
        }
        del[u][v] = 0;
    }
    cout<< "NO";
    return 0;
}