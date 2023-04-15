#include <bits/stdc++.h>
using namespace std;
bool cnt(int x[], int y[], int k, int m, int n){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (m >= x[i] && m >= y[i]){
            cnt++;
        }
    }
    if (cnt >= k) return true;
    else return false;
}
int bs(int x[], int y[], int n, int k, int r, int l){
    if (l <= r){
        int m = l + (r - l) / 2;
        if (cnt(x, y, k, m, n)){
            return bs(x, y, n, k, m - 1, l);
        }
        return bs(x, y, n, k, r, m + 1);
    }
    return l;
}

int main(){
    int n, k; cin >> n >> k;
    int x1, y1;
    int x[n], y[n];
    int r = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x[i] >> y[i];
        if (x[i] > r){
            r = x[i];
        }
        if (y[i] > r){
            r = y[i];
        }
    }
    cout << bs(x, y, n, k, r, 1);   
    return 0;
}
