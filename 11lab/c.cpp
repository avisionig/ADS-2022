#include <bits/stdc++.h>
using namespace std;
 

int n;
vector<int> g[1010];
 

int minKey(int key[], bool mstSet[])
{
    
    int min = INT_MAX, min_index;
 
    for (int i = 0; i < n; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;
 
    return min_index;
}

void prim(vector<int> graph[])
{
    int parent[n];
 
    int key[n];
 
 
    bool mstSet[n];
 
    
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    
    key[0] = 0;
    parent[0] = -1; 
 
    
    for (int count = 0; count < n - 1; count++) {
        
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
 
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    int sum = 0;
    for(int i = 1; i < n; i++) sum += graph[i][parent[i]];
    cout << sum;
}
 

int main() {
    int m, x, y;cin >> n >> m >> x >> y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) g[i].push_back(0);
    }

    for(int i = 0; i < m; i++) {
        string road; cin >> road;
        int a, b, c; cin >> a >> b >> c;
        if(road == "big") {
            g[a - 1][b - 1] = c * x;
            g[b - 1][a - 1] = c * x;
        } else if(road == "small") {
            g[a - 1][b - 1] = c * y;
            g[b - 1][a - 1] = c * y;
        } else {
            if (x < y){
                g[a - 1][b - 1] = c * x;
                g[b - 1][a - 1] = c * x;
            }
            else {
                g[a - 1][b - 1] = c * y;
                g[b - 1][a - 1] = c * y;
            }
        }
    }
    
    prim(g);
 
    return 0;
}