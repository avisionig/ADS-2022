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
void print(int arr[], int size)
{
    for(int i = 0; i < size; i++){
        cout<<char(arr[i]);
    }
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int vow[n];
    for(int i = 0;i < n;i++){
        vow[i] = int(s[i]);
    }
    quickSort(vow, 0 , n - 1);
    print(vow, n);
    return 0;
}