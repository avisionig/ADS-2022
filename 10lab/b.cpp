#include <bits/stdc++.h>
using namespace std;

int bfs(vector <int> mat[], int start, int end, int n){
    deque <int> q;
    bool check[n];
    int dist[n];
    for(int i = 0; i < n; i++){
        check[i] = false;
        dist[i] = INT_MAX;
    }

    check[start] = true;
    dist [start] = 0;
    q.push_back(start);

    while(!q.empty()){
        int temp = q.front();
        q.pop_front();
        for(int i = 0; i < mat[temp].size(); i++){
            if(check[mat[temp][i]] == false){
                check[mat[temp][i]] = true;
                dist[mat[temp][i]] = dist[temp] + 1;
                q.push_back(mat[temp][i]);
            }
            if (mat[temp][i] == end){
                return dist[end];
            }
        }
    }
    return -1;

}
int main(){
    int n; cin >> n;
    vector <int> mat[n];

    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            if (a == 1){
                mat[i].push_back(j);
            }
        }
    }
    int s, e; cin >> s >> e;

    cout << bfs(mat, s - 1, e - 1, n);
}