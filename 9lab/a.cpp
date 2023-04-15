#include <bits/stdc++.h>
using namespace std;


void lpss(string pat, int M, int* lps){
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
}

bool kmp(string txt, string patt){
    int n = txt.size();
    int m = patt.size();

    int lps[m];
    lpss(patt, m, lps);
 
    int i = 0; 
    int j = 0; 
    while (i < n && j < m) {
        if (patt[j] == txt[i]) {
            j++;
            i++;
            if (j == m) {
                return true;
            }
        }
 
        else{
            if (j !=0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

int main(){
    string text; cin >> text;
    string patt; cin >> patt;
    int cnt = 1;
    string ans = text;
    while(ans.size() < patt.size()){
        cnt++;
        ans += text;
    }
    if (kmp(ans, patt)){
        cout << cnt;
    }
    else if (kmp(ans + text, patt)){
        cout << cnt + 1;
    }
    else cout << -1;
    return 0;

}