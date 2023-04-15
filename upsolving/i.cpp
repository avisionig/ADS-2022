#include <bits/stdc++.h>
using namespace std;
string bin(long long n){
    if (n == 0){
        return "";
    }
    string binNum = "";
    while (n > 0){
        binNum = char(n % 2 + 48) + binNum;
        n /=2;
    }
    return binNum;
}
string check(string s){
    long cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1'){
            cnt++;
        }
        else if (cnt > 0){
            cnt--;
        }
        else return "NO";
    }
    if (cnt == 0){
        return "YES";
    }
    else return "NO";
}
int main(){
    int n; cin >> n;
    long long a;
    for (int i = 0; i < n; i++){
        cin >> a;
        cout << check(bin(a)) << endl;
    }
    return 0;
}