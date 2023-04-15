#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int bfs(int mat[][1001], int n, int m, int twos, int ones){
    bool check [n][m];
    int cnt = -1;
     queue <pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = false;
            if(mat[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        cnt++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            int k = q.front().first, p = q.front().second;
            q.pop();
            if (p - 1 >= 0 and check[k][p - 1] == 0 and mat[k][p - 1] == 1){
                check[k][p - 1] = true;
                mat[k][p - 1] = 2;
                twos++;
                ones--;
                q.push({k, p - 1});
            }
            if (p + 1 < m and check[k][p + 1] == 0 and mat[k][p + 1] == 1){
                    check[k][p + 1] = true;
                    mat[k][p + 1] = 2;
                    twos++;
                    ones--;
                    q.push({k, p + 1});
            }
            if (k - 1 >= 0 and check[k - 1][p] == 0 and mat[k - 1][p] == 1){
                
                    check[k - 1][p] = true;
                    mat[k - 1][p] = 2;
                    twos++;
                    ones--;
                    q.push({k - 1, p});
            }
            if (k + 1 < n and check[k + 1][p] == 0 and mat[k + 1][p] == 1){
                
                    check[k + 1][p] = true;
                    mat[k + 1][p] = 2;
                    twos++;
                    ones--;
                    q.push({k + 1, p});
                
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if (mat[i][j] == 1) return -1;
    //     }
    // }
    if (ones > 0){
        return -1;
    }
    return cnt ;
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
    if (ones == 0){
        cout << 0;
        return 0;
    }

    cout << bfs(arr, n, m, twos, ones);
    return 0;

}