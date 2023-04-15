#include <bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str;
    unordered_map <long long, bool> mp;
    int cnt = 0;
    long long q = 9007199254740881;
    for(int i = 0; i < str.size(); i++){
        long long hash = 0;

        for(int j = i; j < str.size(); j++){
            hash = (hash * 256 + str[j]) % q;
            if (mp.find(hash) == mp.end()){
                cnt++;
            }
            mp[hash] = true;
        }
    }
    cout << cnt;
    return 0;
}