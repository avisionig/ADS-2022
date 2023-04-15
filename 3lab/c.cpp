#include <bits/stdc++.h>
using namespace std;
int lbs(int a[],int x, int l, int r){
    if (l <= r){
        int m = l + ( r - l) / 2; 
        if (a[m] >= x){
            return lbs(a, x, l, m - 1);
        }
        else return lbs(a, x, m + 1, r);
    }
    return l;
}
int rbs(int a[],int x, int l, int r){
    if (l <= r){
        int m = l + ( r - l) / 2; 
        if (a[m] <= x){
            return rbs(a, x, m + 1, r);
        }
        else return rbs(a, x, l, m - 1);
    }
    return r;
}

int main(){
    int n; cin >> n;
    int t; cin >> t;
    int queries[n];
    for (int i = 0; i < n ; i++){
        cin >> queries[i];
    }
    sort(queries, queries + n);
    int ans[t];
    for (int i = 0; i < t; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int temp;
        if (l1 > l2){
            temp = l1;
            l1 = l2;
            l2 = temp;
            temp = r1; 
            r1 = r2;
            r2 = temp;
        }
        if (r1 >= l2){
            l2 = r1 + 1;
        }
        int sum = rbs(queries, r1, 0, n - 1) - lbs(queries, l1, 0, n - 1) + 1;
        if (l2 <= r2){
            sum += rbs(queries, r2, 0, n -1) - lbs(queries, l2, 0, n - 1) + 1;
        }
        ans[i] = sum;
    }
    for(int i = 0; i < t; i++){
        cout<< ans[i] << endl;
    }
    return 0;
}