#include <bits/stdc++.h>
using namespace std;
int bs(int a[], int x, int l, int r){
    if (r >= l){
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        else if(a[m] > x) return bs(a, x, l, m - 1);
        return bs(a, x, m + 1, r);
    }
    return l;
}
int main(){
    int n, m , x; cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (i != 0){
            a[i] += a[i - 1];
        }
    }
    for (int i = 0; i < m; i++){
            cin >> x;
            cout << bs(a, x, 0, n - 1) + 1 << endl;
        }
}