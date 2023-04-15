#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<int> v[n];
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        v[--x].push_back(--y);
    }
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if (v[i].size() > maxi){
            maxi = v[i].size();
        }
    }
    for(int i = 0; i < n; i++){
        if (maxi == v[i].size()){
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}