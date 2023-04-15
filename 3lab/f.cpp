#include <bits/stdc++.h>
using namespace std;
int bs(int a[], int x, int l, int r){
    if (l <= r){
        int m = l + (r - l) / 2;
        if(a[m] <= x){
            return bs(a, x, m + 1, r);
        }
        else if ( a[m] > x){
            return bs(a, x, l, m - 1);
        }
    }
    return l;
}
int main(){
    int n; cin >> n;
    int enemy[n];
    for (int i = 0; i < n; i++){
        cin >> enemy[i];
    }
    sort(enemy, enemy + n);
    int rounds; cin >> rounds;
    int markp[rounds];
    for (int i = 0; i < rounds; i++){
        cin >> markp[i];
    }
    for (int i = 0; i < rounds; i++){
        int index = bs(enemy, markp[i], 0, n - 1);
        int sum = 0;
        for (int j = 0; j < index; j++){
            sum += enemy[j];
        }
        cout << index << " " << sum << endl;
    }
    return 0;
}