#include <bits/stdc++.h>
using namespace std;
struct matrix{
    int sum ;
    int size;
    int arr[500];
    matrix(){
        sum = 0;
        size = 0;
    }
    void add(int x){
        arr[size] = x;
        size++;
        sum += x;
    }
};
bool compare_mat(matrix a, matrix b){
    if (a.sum > b.sum){
        return true;
    }
    else if (a.sum == b.sum){
        for(int i = 0; i < a.size; i++){
            if (a.arr[i] != b.arr[i]){
                return a.arr[i] < b.arr[i];
            }
        }
    }
    return false;
}
void merge(matrix arr[], int l, int m, int r) {
  
  int n1 = m - l + 1;
  int n2 = r - m;

  matrix a[n1], b[n2];

  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    b[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (compare_mat(a[i], b[j])) {
      arr[k] = a[i];
      i++;
    } else {
      arr[k] = b[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = a[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = b[j];
    j++;
    k++;
  }
}


void mergeSort(matrix arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(){
    int n, m; cin >> n >> m;
    matrix arr[n];
    int a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a;
            arr[i].add(a);
        }
    }
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i].arr[j] << " ";
        }
        cout << endl;
    }
}