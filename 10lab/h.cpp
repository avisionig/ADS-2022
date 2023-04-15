#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
int bfs(char mat[][100], int n, int m){
    bool check [n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!check[i][j] and mat[i][j] == '1'){
                cnt++;
                check[i][j] = true;
                queue <pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int k = q.front().first, p = q.front().second;
                    if (p - 1 >= 0){
                        if(check[k][p - 1] == 0){
                            check[k][p - 1] = true;
                            if(mat[k][p - 1] == '1'){
                                q.push({k, p - 1});
                            }
                        }
                    }
                    if (p + 1 < m){
                        if (check[k][p + 1] == 0){
                            check[k][p + 1] = true;
                            if(mat[k][p + 1] == '1'){
                                q.push({k, p + 1});
                            }
                        }
                    }
                    if (k - 1 >= 0){
                        if(check[k - 1][p] == 0){
                            check[k - 1][p] = true;
                            if(mat[k - 1][p] == '1'){
                                q.push({k - 1, p});
                            }
                        }
                    }
                    if (k + 1 < n){
                        if (check[k + 1][p] == 0){
                            check[k + 1][p] = true;
                            if(mat[k + 1][p] == '1'){
                                q.push({k + 1, p});
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    return cnt;
}
int main(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << bfs(arr, n, m);
    return 0;

}