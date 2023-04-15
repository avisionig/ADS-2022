#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> arr){
    vector<int> temp[n];
    for(int i = 0; i < arr.size(); i++){
        temp[arr[i][1]].push_back(arr[i][0]);
    }
    vector <int> p;
    for(int i = 0; i < n; i++){
        p.push_back(0);
    }
    for(int i = 0; i < n; i++){
        for(auto j :temp[i]){
            p[j]++;
        }
    }

    queue <int> q;
    for(int i = 0; i < n; i++){
        if(p[i] == 0){
            q.push(i);
        }
    }
    vector <int> res;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        res.push_back(f);
        for(int j = 0; j < temp[f].size(); j++){
            p[temp[f][j]]--; 
            if (p[temp[f][j]] == 0) q.push(temp[f][j]);
        }
    }

    if(res.size() == n){
        cout << "Possible" << endl;
        for(int i = 0; i < n; i++){
            cout << res[i] + 1<< " ";
        }
        return;
    }

    cout << "Impossible";
    return;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> arr;
    int x, y;
    for(int i = 0 ; i < m; i++){
        cin >> x >> y;
        arr.push_back({x, y});
    }
    bfs(n, arr);
}