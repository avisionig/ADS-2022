#include <bits/stdc++.h>
using namespace std;

bool binSearch(int arr[], int x, int l, int r){
    if (l <= r){
        int m = l + (r - l)/2;
        if (arr[m] == x){
            return true;
        }
        if (arr[m] > x){
            return binSearch(arr, x, l, m - 1);
        }
        return binSearch(arr,x , m + 1, r);
    }
    return false;
}
int main (){
    int m; cin >> m;
    int n; cin >> n;
    int arr[n]; 
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++){
        if (binSearch(arr, m - arr[i], 0, n - 1)){
            cout << arr[i] << " " << m - arr[i];
            return 0;
        }
    }
}