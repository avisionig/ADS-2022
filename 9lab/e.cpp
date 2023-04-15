#include <bits/stdc++.h>
using namespace std;

int pref(string pat){
    int M = pat.size();
    int lps[M];
    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[M - 1];
}

int main(){
    int n; cin >> n;
    int k;
    string text; //cin >> text;
    for(int i = 0; i < n; i++){
        cin >> text >> k;
        cout << text.size() + (k - 1) * (text.size() - pref(text)) << endl;
    }
    return 0;
}