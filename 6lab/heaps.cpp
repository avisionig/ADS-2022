#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int large = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] < arr[large]){
        large = l;
    }
    if (r < n and arr[r] < arr[large]){
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
int main(){
    int n, m; cin >> n >> m;

    int arr[m][n];

    for (int i = 0; i < n ; i++){
        for(int j = 0; j < m;j++){
            cin >> arr[j][i];
        }
    }
    for(int i = 0; i < m ;i++){
        heapSort(arr[i], n);
    }
    for (int i = 0; i < n ; i++){
        for(int j = 0; j < m;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}