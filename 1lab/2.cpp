#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n ){
    for (int i = 2; i < int(sqrt(n) + 1); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
int nthSuperPrime(int n){
    if (n == 1) return 3;
    else{
        vector<int> prime;
        vector<int> superprime;
        for (int i = 2; i < n * n * n; i++){
            if(isPrime(i) == true){
                prime.push_back(i);
            }
        }
        for (int i = 2; i < prime.size();i++){
            if (isPrime(i) == true){
                superprime.push_back(prime[i - 1]);
            }

        }
        return superprime[n - 1];
    }
}
int main(){
    int n;cin >> n;
    cout<<nthSuperPrime(n);
}