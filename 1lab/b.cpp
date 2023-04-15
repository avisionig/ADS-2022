#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector <int> v;
    queue <int> ans;
    ans.push(-1);
    for (int i = 0;i < n; i++){
        int a;cin>> a;
        v.push_back(a);
    }
    for (int i = 1; i < n; i++){
        int mini = v[i - 1];
        int j = i - 1;
        while (j >= 0){
            if (v[j] < mini){
                mini = v[j];
            }
            j--;
        }
        if (mini > v[i]){
            ans.push(-1);
        }
        else{
            for (int k = i - 1; k >= 0; k--){
                if (v[k] <= v[i]){
                    ans.push(v[k]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n;i++){
        cout<<ans.front()<<" ";
        ans.pop();
    }
     return 0;
}