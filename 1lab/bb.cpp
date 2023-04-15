#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> v;
    for(int i = 0; i < n; i++){
        int a;cin >> a;
        v.push_back(a);
    }
    stack <int> ans;
    while(!v.empty()){
        stack <int> st;
        int i = -1;
        while(!ans.empty()){
            if(ans.top() <= v.front()){
                i = ans.top();
                break;
            }
            int t = ans.top();
            ans.pop();
            st.push(t);
        }
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        ans.push(v.front());
        v.erase(v.begin());
        cout << i << ' ';
    }
    return 0;
}