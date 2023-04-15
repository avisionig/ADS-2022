#include <bits/stdc++.h>
using namespace std; 

vector<int>g1[410]; 
vector<int>g2[410]; 
int arr[405][405]; 

int ans(int n) {
    queue<int> q1, q2; 
    vector<int> d1(n + 1), d2(n + 1); 
    vector<bool> used1(n + 1), used2(n + 1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < g1[v].size(); i++){ 
            if(!used1[g1[v][i]]){ 
                used1[g1[v][i]] = true; 
                q1.push(g1[v][i]); 
                d1[g1[v][i]] = d1[v]+1; 
            } 
        } 
    } 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0; i < g2[v].size(); i++){ 
            if(!used2[g2[v][i]]){ 
                used2[g2[v][i]] = true; 
                q2.push(g2[v][i]);
                d2[g2[v][i]] = d2[v] + 1; 
            } 
        } 
    } 
    if (!used1[n - 1] || !used2[n - 1]) return -1; 
    return max(d1[n - 1], d2[n - 1]); 
}

int main(){ 
    int n, m; 
    cin >> n >> m; 
    for(int i = 0; i < m; i++){ 
        int a, b; 
        cin >> a >> b; 
        a--; b--; 
        g1[a].push_back(b); 
        g1[b].push_back(a); 
        arr[a][b] = 1;  
        arr[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (!arr[i][j] && i != j){ 
                g2[i].push_back(j); 
            } 
        } 
    } 
    
    cout << ans(n);
}