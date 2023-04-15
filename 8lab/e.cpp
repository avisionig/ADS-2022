#include <bits/stdc++.h>
using namespace std;
char rehashing(long long n, long long sum, int i){
    int ascii = (n - sum)/ pow(2, i) + 97;
    return (char)ascii;
}
int main(){
    int n; cin >> n;
    long long arr[n];
    long long sum = 0;
    string ans = "";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (i == 0){
            ans += ans + rehashing(arr[i], 0, i);
        }
        else if (i > 0){
            sum = arr[i - 1];
            ans += rehashing(arr[i], sum, i);
        }
    }
    cout << ans;
    return 0;
}