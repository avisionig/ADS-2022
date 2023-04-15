#include <bits/stdc++.h>
using namespace std;
set <int> ans;

void lsparray(string pat, int M, int* lps){
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

int KMPSearch(string txt, string patt){
    int n = txt.size();
    int m = patt.size();

    int lps[m];
    
    int cnt = 0;
    lsparray(patt, m, lps);
 
    int i = 0; 
    int j = 0; 
    while ((n - i) >= (m - j)) {
        if (patt[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == m) {
            cnt++;
            ans.insert(i - j);
            j = lps[j - 1];
        }
 
        else if (i < n && patt[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return cnt;
}

int main(){
    string text; cin >> text;
    string patt; cin >> patt;
    cout << KMPSearch(text, patt) << endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << *it + 1<< " ";
    }
    return 0;
}