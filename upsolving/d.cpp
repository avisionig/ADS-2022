#include <bits/stdc++.h>
using namespace std;
int primeFact(int n){
    int i = 2;
    unordered_map <int, int> mp;
    while (n > 1){
        if (n % i == 0){
            n /= i;
            mp[i] += 1;
        }
        else {
            i++;
        }
    }
    return mp.size();
}
int main(){
    int n; cin >> n;
    cout << primeFact(n);
    return 0;
}