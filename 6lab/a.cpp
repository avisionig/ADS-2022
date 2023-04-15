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
    int n, v = 0, c = 0;
    cin >> n;
    int vow[n];
    int cons[n];
    char a;
    for(int i = 0;i < n;i++){
        cin >> a;
        if (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u'){
            vow[v] = int(a);
            v++;
        }
        else {
            cons[c] = int(a);
            c++;
        }
    }
    quickSort(vow, 0 , v - 1);
    quickSort(cons, 0, c - 1);
    print(vow, v);
    print(cons, c);
    return 0;
}