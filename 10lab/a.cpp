#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int bfs(int mat[][1000], int n, int m, int twos, int ones){
    bool check [n][m];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (mat[i][j] == 1)check[i][j] = false;
            else if (mat[i][j] == 2)check[i][j] = false;
            else check[i][j] = true;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(twos - 1 >= ones){
                return cnt;
            }
            
            if(!check[i][j] and mat[i][j] == 2){
                check[i][j] = true;
                queue <pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int temp = 0;
                    int k = q.front().first, p = q.front().second;
                    if (p - 1 >= 0){
                        if(check[k][p - 1] == 0 and mat[k][p - 1] == 1){
                            check[k][p - 1] = true;
                            mat[k][p - 1] == 2;
                            twos++;
                            q.push({k, p - 1});
                            temp++;
                        }
                    }
                    if (p + 1 < m){
                        if (check[k][p + 1] == 0 and mat[k][p + 1] == 1){
                            check[k][p + 1] = true;
                            mat[k][p + 1] == 2;
                            twos++;
                            temp++;
                            q.push({k, p + 1});
                        }
                    }
                    if (k - 1 >= 0){
                        if(check[k - 1][p] == 0 and mat[k - 1][p] == 1){
                            check[k - 1][p] = true;
                            mat[k - 1][p] == 2;
                            twos++;
                            temp++;
                            q.push({k - 1, p});
                        }
                    }
                    if (k + 1 < n){
                        if (check[k + 1][p] == 0 and mat[k + 1][p] == 1){
                            check[k + 1][p] = true;
                            mat[k + 1][p] == 2;
                            twos++;
                            temp++;
                            q.push({k + 1, p});
                        }
                    }
                    if(temp > 0){
                        cnt++;
                    }
                    q.pop();
                }
            }
        }
    }
    return -1;
}
int main(){
    int n, m; cin >> n >> m;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 2){
                twos++;
            }
            else if(arr[i][j] == 1) ones++;
        }
    }
    cout << bfs(arr, n, m, twos, ones);
    return 0;

}