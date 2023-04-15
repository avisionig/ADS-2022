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
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    /*for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    int mindiff = abs(arr[0] - arr[1]);
    for(int i = 2; i < n; i++){
        int temp = abs(arr[i - 1] - arr[i]);
        if (temp < mindiff){
            mindiff = temp;
        }
    }
    for(int i = 1; i < n; i++){
        if (abs(arr[i - 1] - arr[i]) == mindiff){
            cout << arr[i - 1] << " " << arr[i] << " ";
        }
    }
    return 0;
}