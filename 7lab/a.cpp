#include <bits/stdc++.h>
using namespace std;
bool comapre_str(string a, string b){
    if (a.size() <= b.size()){
        return true;
    }
    else if (a.size() == b.size()){
        return a <= b;
    }
    return false;
}
void merge(string arr[], int l, int m, int r) {
  
  int n1 = m - l + 1;
  int n2 = r - m;

  string a[n1], b[n2];

  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    b[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (comapre_str(a[i], b[j])) {
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


void mergeSort(string arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(){
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string st[50];
        string s;
        int j = 0;
        getline(cin , s);
        stringstream stream(s);
        string tok;
        while(getline(stream, tok, ' ')){
            st[j] = tok;
            j++;
        }
        mergeSort(st, 0, j - 1);
        for(int i =0 ; i < j; i++){
            cout << st[i] << " ";
        }
        cout << endl;
    }
    return 0;
}