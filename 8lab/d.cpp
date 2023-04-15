#include <bits/stdc++.h>
using namespace std;

int count(string t, string s){
    int cntt = 0;
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
        if(d == (h_s * p[i]) % q && t.substr(i, m) == s){
            cntt++;
        }
    }
    return cntt;
}


int main(){
    int n;
    cin >> n;
    while(n != 0){
        string arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        string text;
        cin >> text;
        vector <pair<string, int>> ans;
        int maxcnt = 0;
        int cntcnt = 0;
        for(int i = 0; i < n; i++){
            cntcnt = count(text, arr[i]);
            if (maxcnt < cntcnt){
                maxcnt = cntcnt;
            }
            ans.push_back(make_pair(arr[i], cntcnt));
        }
        
        cout << maxcnt << endl;

        for(int i = 0; i < n; i++){
            if (ans[i].second == maxcnt){
                cout << ans[i].first << endl;
            }
        }
        cin >> n;
    }
    return 0;
}
