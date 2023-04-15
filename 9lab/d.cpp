#include <bits/stdc++.h>
using namespace std;

int pref(string pat, int M){
    int lps[M];

    int len = 0;
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len] || pat[i] == pat[len] + 32) {
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
// int kmp(string txt, string patt){
//     int n = txt.size();
//     int m = patt.size();

//     int lps[m];
//     pref(patt, m, lps);
    
//     int i = 0; 
//     int j = 0; 
//     while ((n - i) >= (m - j)) {
//         if (patt[j] == txt[i]) {
//             j++;
//             i++;
//         }
 
//         if (j == m) {
//             return i - j;
//             j = lps[j - 1];
//         }
 
//         else if (i < n && patt[j] != txt[i]) {
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i = i + 1;
//         }
//     }
//     return -1;
// }
int main(){
    string city; cin >> city;
    
    int n; cin >> n;
    string arr[n];

    int maxi = 0;
    int cnt = 0;
    vector <pair<string, int>> ans;
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        string p = arr[i] + "#" + city;
        int tempmaxi = pref(p, p.size());
        
        ans.push_back(make_pair(arr[i], tempmaxi));

        if (tempmaxi > maxi){
            maxi = tempmaxi;
            cnt = 1;
        }
        else if (tempmaxi == maxi){
            cnt++;
        }

    }
    if(maxi == 0) {
        cout << 0;
        return 0;
    }
    cout << cnt << endl;
    for(auto x : ans){
        if (x.second == maxi){
            cout << x.first << endl;
        }
    }
    return 0;
}