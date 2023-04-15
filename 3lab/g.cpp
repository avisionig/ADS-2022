#include <bits/stdc++.h>
using namespace std;
int check (int c[], int n, int f, int m){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += c[i]/m;
        if (c[i] % m) cnt++;
    }
    if (cnt <= f) return true;
    else return false;
}
int bs(int c[], int l, int r, int f, int n){
    if ( l <= r){
        int m = l + ( r - l) / 2;
        if (check(c, n, f, m)){
            return bs(c, l, m - 1, f, n);
        }
        return bs(c, m + 1, r, f, n);
    }
    return l;
}

int main(){
    int n, f; cin >> n >> f;
    int c[n];
    int l = 1, r = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        if (c[i] > r){
            r = c[i] - 1;
        }
    }    
    cout << bs(c, l, r, f, n);
    return 0;
}