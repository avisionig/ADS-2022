#include <bits/stdc++.h>
using namespace std; 
 int a[800][800];
int search(int a[][800], int x, int l, int r,int k){
    if (r <= l){
        int mid = l + (r - l) / 2;
        if (mid % 2 == 0){
            if(a[mid][0] >= x and x >= a[mid][k]){
                return mid;
            }
            else if (a[mid][0] < x){
                return search(a, x, mid - 1, r, k);
            }
            else if (a[mid][k] > x){
                return search(a, x, l, mid + 1, k);
            }
        }
        else{
            if(a[mid][k] >= x && a[mid][0] <= x){
                return mid;
            }
            else if (a[mid][0] > x){
                return search(a, x, l, mid + 1, k);
            }
            else if (a[mid][k] < x){
                return search(a, x, mid - 1, r, k);
            }
        }
    }
    return -1;
}
int binSearch(int a[], int x, int l, int r, int k){
    if (k % 2 == 0){
        if (r >= l){
            int mid = l + (r - l)/2;
            if (a[mid] == x){
                return mid;
            }
            else if (a[mid] > x){
                return binSearch(a, x, mid + 1, r, k);
            }
            else if (a[mid] < x){
                return binSearch(a, x, l, mid - 1, k);
            }
        }
        return -1;
    }
    else{
        if (r >= l){
            int mid = l + (r - l)/2;
            if (a[mid] == x){
                return mid;
            }
            else if (a[mid] > x){
                return binSearch(a, x, l, mid - 1, k);
            }
            else if (a[mid] < x){
                return binSearch(a, x, mid + 1, r, k);
            }
        }
        return -1;
        }
    return -1;
}

int main(){
    map <int, pair<int, int>> ans;
    int t; cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++){
        cin >> arr[i];
    }
    int n , m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < t ; i++){
        int y = 0;
        int x = search(a, arr[i], n - 1, 0, m - 1);
        if (x != -1){
            y = binSearch(a[x], arr[i], 0, m - 1, x);
        }
        ans[i] = make_pair(x,y);
    }
    map <int, pair<int, int>> :: iterator it;
    for (it = ans.begin(); it != ans.end(); ++it){
        if ( it -> second.first == -1 || it -> second.second == -1){
            cout<< -1 << endl;
        }
        else cout << it -> second.first << " " << it -> second.second << endl;
    }
    return 0;
}