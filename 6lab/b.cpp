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
        if (arr[j] < pivot){
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
    int arr[n], arrr[m];
    int a;
    for(int i = 0; i < n;i ++){
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        cin >> arrr[i]; 
    }
    quickSort(arr, 0, n - 1);
    quickSort(arrr, 0, m - 1);
    
    map <int, int> mp;

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    for(int  i = 0; i < m; i++){
        if (mp[arrr[i]] > 0){
            mp[arrr[i]]--;
            cout << arrr[i] << " ";
        }
    }
    /*while ( i < n && j < m){
        if (arr[i] == arrr[j]){
            cout << arr[i] << " ";
            i++;
            j++;
        }
        else if (arr[i] > arrr[j]){
            j++;
        }
        else{
            i++;
        }
    }*/

    return 0;
}