#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    stack <char> st;
    int n = s.size();
    bool flag = false;
    for (int i = 1;i < n ; i++){
        st.push(s[i - 1]);
        if (flag == true){
            st.pop();
        }
        if (s[i] == st.top()){
            st.pop();
            flag = true;
        }
    }

    if (st.empty() == true){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}