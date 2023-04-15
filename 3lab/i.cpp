#include <bits/stdc++.h>
using namespace std;

bool binSearch(int a[], int x, int l, int r){
    if ( r >= l){
        int m = l + (r - l) / 2;
        if (a[m] == x){
            return true;
        }
        else if( a[m] > x){
            return binSearch(a, x, l, m - 1);
        }
        return binSearch (a, x, m + 1, r);
    }
    return false;
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x; cin >> x;
    if (!binSearch( a, x, 0, n - 1 )){
        cout << "No";
        return 0;
    }
    cout << "Yes";
}