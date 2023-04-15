#include <bits/stdc++.h>
using namespace std;
string bfs(vector <int> mat[], int start, int end, int n){
    deque <int> q;
    bool check[n];
    for(int i = 0; i < n; i++){
        check[i] = false;
    }

    check[start] = true;
    q.push_back(start);

    while(!q.empty()){
        int temp = q.front();
        q.pop_front();
        for(int i = 0; i < mat[temp].size(); i++){
            if(check[mat[temp][i]] == false){
                check[mat[temp][i]] = true;
                q.push_back(mat[temp][i]);
            }
            if (mat[temp][i] == end){
                return "YES";
            }
        }
    }
    return "NO";

}
int main(){
    int n, m; cin >> n >> m;
    vector <int> mat[n];
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        mat[x - 1].push_back(y - 1);
        mat[y - 1].push_back(x - 1);
    } 
    int s, f; cin >> s >> f;
    cout << bfs(mat, s - 1, f - 1, n);
    return 0;
}