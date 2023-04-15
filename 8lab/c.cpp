#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

void count(string t, string s){
    int n = t.size();
    int m = s.size();
    long long h[n];
    long long p[n];
    long long q = 2147483647;
    p[0] = 1;
    for(int i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(int i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_s = 0;
    for(int i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(int i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1];
        if(i > 0){
            d = (d - h[i-1] + q) % q;
        }
        if(d == (h_s * p[i]) % q){
            ans.push_back(i);
            int k = 1;
            while(k < s.size()){
                ans.push_back(i + k);
                k++;
            }
        }
    }
}


int main(){
    string s; cin >> s;
    int n; cin >> n;
    string arr[n];
    set <int> st;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        count(s, arr[i]);
    }
    for(auto x : ans){
        st.insert(x);
    }
    if (st.size() == s.size()){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" ;
    return 0;

}