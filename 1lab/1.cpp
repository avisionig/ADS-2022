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

int main(){
    int n; cin>>n;
    if (isPrime(n) == true and n > 1){
        cout<<"YES";
    }
    else cout<<"NO";

}