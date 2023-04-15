#include <bits/stdc++.h>
using namespace std;

bool bfs(vector <int> mat[], int start, int end, int n){
    queue <int> q;
    bool check[n];
    for(int i = 0; i < n; i++){
        check[i] = false;
    }

    check[start] = true;
    q.push(start);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if (end == temp){
            return true;
        }

        for(int i = 0; i < mat[temp].size(); i++){
            if(check[mat[temp][i]] == false){
                check[mat[temp][i]] = true;
                q.push(mat[temp][i]);
            }
        }
    }
    return false;

}
int main(){
    int n, q; cin >> n >> q;
    int mat[n][n];

    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    while(q > 0){  
        int a, b, c; cin >> a >> b >> c;
        if (mat[a - 1][b - 1] == 1 && mat[b - 1][c - 1] == 1 && mat[a - 1][c - 1] == 1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        q--;
    }
    return 0;
}