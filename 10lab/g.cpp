#include<bits/stdc++.h>
using namespace std;
 
vector<int> g[1000];
vector<pair<int, int>> c;
int vis[1000], cycle, e[1000][1000];
 
void getCycle(int u){
    vis[u]= 1;
 
    for(int i = 0; i < g[u].size(); i++){
        int node= g[u][i];
        if(!vis[node]){
            c.push_back({u,node});
            getCycle(node);
            if(cycle)  return;
        }
 
        if(vis[node]==1){
            c.push_back({u,node});
            cycle = 1;
            return;
        }
    }
 
    vis[u]= 2;
}
 
void dfs(int u){
    vis[u]= 1;
 
    for(int i = 0; i < g[u].size(); i++){
        int node= g[u][i];
        if(e[u][node])  continue;
 
        if(!vis[node]){
            dfs(node);
            if(cycle)  return;
        }
 
        if(vis[node]==1){
            cycle= 1;
            return;
        }
    }
 
    vis[u]= 2;
}
 
int main(){
    int n, m;cin >> n >> m;
    
    cycle = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        vis[i] = 0;
    }

    for(int i=1;i<=n;i++){
        if(!cycle && !vis[i])
            getCycle(i);
    }
 
    if(!cycle){
        cout<<"YES";
        return 0;
    }
 
    for(int i = 0; i < c.size(); i++){
        int f=c[i].first, s=c[i].second;

        for(int k = 0; k < m; k++){
            vis[k] = 0;
        }

        e[f][s]= 1;
        cycle=0;
 
        for(int j=1; j<=n; j++)
            if(!vis[j])
                dfs(j);
 
        if(!cycle){
            cout<<"YES";
            return 0;
        }
 
        e[f][s]= 0;
    }
 
    cout<<"NO";
    return 0;
}