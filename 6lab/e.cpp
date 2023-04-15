#include <bits/stdc++.h>
using namespace std;
void swapp(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int part(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++){
        if (arr[j] > pivot){
            i++;
            swapp(&arr[i], &arr[j]);
        }
    } 
    swapp(&arr[i+1], &arr[r]);
    return (i + 1);
}
void quickSort(int arr[], int l, int r){
    if (l < r){
        int p = part(arr, l , r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
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
        quickSort(arr[i],0, n - 1);
    }
    for (int i = 0; i < n ; i++){
        for(int j = 0; j < m;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}