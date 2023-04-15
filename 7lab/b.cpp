#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
  
  int n1 = m - l + 1;
  int n2 = r - m;

  int a[n1], b[n2];

  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    b[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
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


void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(){
    int n; cin >> n;
    vector <int> a;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        a.push_back(num);
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++){
        cin >> num;
        a.push_back(num);
    }
    int arr[n + m];
    for (int i = 0; i < n + m;i++){
        arr[i] = a[i];
    }
    mergeSort(arr, 0, n + m - 1);

    for (int i = 0; i < n + m;i++){
        cout << arr[i] << " ";
    }
    return 0;
}