#include <bits/stdc++.h>
using namespace std;
vector<int>g1[500]; 
vector<int>g2[500]; 
int arr[500][500];

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
        int x,y; cin >> x >> y;
        x--;y--;
        g1[x].push_back(y);
        g2[y].push_back(x);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0 and i != j){
                g2[i].push_back(j);
            }
        }
    }
    
    queue<int> q1, q2; 
    vector<int> p1(n + 1), p2(n + 1); 
    vector<bool> c1(n + 1), c2(n + 1);

    q1.push(0); 
    c1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < g1[v].size(); i++){ 
            if(!c1[g1[v][i]]){ 
                c1[g1[v][i]] = true; 
                q1.push(g1[v][i]); 
                p1[g1[v][i]] = p1[v]+1; 
            } 
        } 
    } 
    q2.push(0); 
    c2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0; i < g2[v].size(); i++){ 
            if(!c2[g2[v][i]]){ 
                c2[g2[v][i]] = true; 
                q2.push(g2[v][i]);
                p2[g2[v][i]] = p2[v] + 1; 
            } 
        } 
    }  

    if(!p1[n-1] or !p2[n-1]){
        cout << -1;
        return 0;
    }

    cout << max(c1[n-1],c2[n-1]);
    return 0;
}