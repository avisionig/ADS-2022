#include <bits/stdc++.h>
using namespace std;
long cnt (long arr[], int n, long m){
    int cnt = 0;
    long temp = 0;
    for (int i = 0; i < n; i++){
        if (temp + arr[i] > m){
            cnt++;
            temp = 0;
        }
        temp += arr[i];
    }
    return cnt;
}
long binarySeacrh(long arr[], long l, long r , int n, int k){
    if (l <= r){
        long m = l + (r - l) / 2;
        long cnt_1 = cnt(arr, n, m);
        if (cnt_1 + 1 <= k) return binarySeacrh(arr,l , m - 1, n,k);
        else return binarySeacrh(arr, m + 1, r, n, k);
    }
    return l;
}
int main(){
    int n; cin >> n;
    int k; cin >> k;
    long arr[n];
    long l = 1, r = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        r += arr[i];
        l = max(l , arr[i]);
    }
    cout << binarySeacrh(arr, l, r, n,k);
    return 0;
}