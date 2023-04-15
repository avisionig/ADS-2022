#include <bits/stdc++.h>
using namespace std;
#define d 26

int rabinKarp(string patt, string text, int q) {
    int cnt = 0;
    int m = patt.size();
    int n = text.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + patt[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != patt[j])
            break;
         }

        if (j == m)
            cnt++;
        }

        if (i < n - m) {
        t = (d * (t - text[i] * h) + text[i + m]) % q;

        if (t < 0)
            t = (t + q);
        }
    }
    return cnt;
}





long long newHash(string text, int old , int nw, long long oldHash, int n){
    long long newHashCode = oldHash - text[old];
    newHashCode = newHashCode / 26;
    newHashCode += text[nw] * pow(26, n - 1);
    return newHashCode;
}
long long hashing(string text, int end ){
    long long hashCode = 0;
    for(int i = 0; i <= end; i++){
        hashCode += text[i] * pow(26, i);
    }
    return hashCode;
}

bool equalStr(string str1, int st1, int end1, string str2, int st2, int end2){
    if (end1 - st1 != end2 - st2){
        return false;
    }
    while(st1 <= end1 && st2 <= end2){
        if (str1[st1] != str2[st2]){
            return false;
        }
        st1++;
        st2++;
    }
    return true;
}
int cntnt(string text, string patt){
    int cnt = 0;
    int n = text.size();
    int m = patt.size();
    long long pattHash = hashing(patt, m - 1);
    long long textHash = hashing(text, m - 1);
    for(int i = 1; i <= n - m + 1; i++){
        if (pattHash == textHash /*&& equalStr(text, i - 1, i + m - 2, patt, 0 , m - 1)*/){
            cnt++;
        }
        if(i < n - m + 1){
            textHash = newHash(text, i - 1, i + m - 1, textHash, m);
        }
    }
    return cnt;
}




unordered_map <size_t, size_t> mp;
size_t cnt = 0;

void count(string t, string s){
    size_t n = t.size();
    size_t m = s.size();
    long long h[n];
    long long p[n];
    long long q = 2147483647;
    p[0] = 1;
    for(size_t i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }
    for(size_t i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    long long h_s = 0;
    for(size_t i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for(size_t i = 0; i + m - 1 < n; i++){
        long long dd = h[i + m - 1];
        if(i > 0){
            dd = (dd - h[i-1] + q) % q;
        }
        if(dd == (h_s * p[i]) % q){
            mp[i]++;
            if(mp[i] > 1) cnt++;
        }
    }
}