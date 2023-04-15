#include <bits/stdc++.h>
using namespace std;


void dfs(int v, int vis[], int child[], vector<int> g[]){
    int cnt = 0;
    vis[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if (vis[g[v][i]] == 0){
            cnt++;
            child[v] = cnt;
            dfs(g[v][i], vis, child, g);
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    vector<int> g[n ];
    int vis[n], child[n], root[n];

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
        // g[--y].push_back(--x);
    }
    int bf = 0;

    for(int i = 0; i < n; i++){
        vis[i] = 0;
        child[i] = 0;
        root[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            root[i] = 1;
            dfs(i, vis, child, g);
            bf++;
        }
    }   
    for(int i = 0; i < n; i++){
            for(int j = 0; j < g[i].size(); j++){
                if (child[i] < child[g[i][j]]){
                    bf++;
                }
            }
        }
    cout << bf;
    return 0;
}