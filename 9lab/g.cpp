#include <bits/stdc++.h>
using namespace std;

void pref(string pat, int M, int* lps){
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
int main(){
    string text; cin >> text;
    int lsp[text.size()];
    int cnt = 0;
    pref(text, text.size(), lsp);
    // for (int i = 0; i < text.size(); i++){
    //     cout << lsp[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < text.size(); i++){
    //     if (lsp[i] == 0){
    //         cnt++;
    //     }
    //     else{
    //         break;
    //     }
    // }
    cout << text.size() - lsp[text.size() - 1];
    return 0;
}