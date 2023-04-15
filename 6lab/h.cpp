#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int large = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[large]){
        large = l;
    }
    if (r < n and arr[r] > arr[large]){
        large = r;
    }
    if (large != i){
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}
void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr,n, i);
    }
    for (int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int binSearch(int arr[], int l, int r, int x, int res){
    if (l <= r){
        int m = (r + l) / 2;
        if (arr[m] <= x){
            return binSearch(arr, m + 1, r, x, res);
        }
        else if (arr[m] > x){
            return binSearch(arr, l, m - 1, x, arr[m]);
        }
    }
    if (res == 0){
            res = arr[0];
        }
    return res;
}
int main(){
    int n; cin >> n;
    char a;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> a;
        arr[i] = (int)a;
    }
    
    heapSort(arr,n);
    char find; cin >> find;

    int ans = binSearch(arr, 0, n - 1, (int)find, 0);

    cout << char(ans);
    return 0;
}