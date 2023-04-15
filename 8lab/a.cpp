#include <bits/stdc++.h>
using namespace std;
long long q = 1000000007;

long long hashC(string text){
    int n = text.size();
    long long p[n];
    p[0] = 1;   
    for(int i = 1; i < n ; i++){
        p[i] = (p[i - 1] * 11) % q;
    }
    long long hashCode = 0;
    for(int i = 0; i < n; i++){
        hashCode += (text[i] - '0' + 1) * p[i] % q;
    }
    return hashCode % q;
}

int main(){
    int n; cin >> n;
    string arr[n * 2];
    unordered_map <string, bool> ans;
    for(int i = 0; i < n * 2; i++){
        cin >> arr[i];
        ans[arr[i]] = true;
    }    
    int cnt = 0;
    for (int i = 0; i < n * 2; i++){
        if (n == cnt){
            break;
        }
        string hashCode = to_string(hashC(arr[i]));
        if(ans[hashCode]){
            cout << "Hash of string " << '"' << arr[i] << '"' << " is " << hashCode << endl;
            cnt++;
        }
    }
    /*
    for (int i = 0; i < n * 2; i++){
        auto it = ans.find(arr[i]);
        if (it == ans.end()){
            auto iti = ans.find(to_string(hashC(arr[i])));
            if (iti != ans.end()){
                cout << "Hash of string " << '"' << arr[i] << '"' << " is " << iti->first << endl;
            }
        }
    }*/
    
    return 0;
}