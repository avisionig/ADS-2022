#include <bits/stdc++.h>
using namespace std;

string lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int arr[n + 1][m + 1];
 
    int len = 0;
    int row, col;
 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0)
                arr[i][j] = 0;
 
            else if (s[i - 1] == t[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                if (len < arr[i][j]) {
                    len = arr[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                arr[i][j] = 0;
        }
    }
    string res (len, 'a');
    while (arr[row][col] != 0) {
        res[--len] = s[row - 1]; 
        row--;
        col--;
    }

    return res;
}
int main(){
    int n; cin >> n;
    string arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if (i > 0){
            arr[i] = lcs(arr[i-1], arr[i]);
        }
    }
    cout << arr[n-1];
}
