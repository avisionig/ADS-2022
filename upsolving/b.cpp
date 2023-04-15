#include <bits/stdc++.h>
using namespace std;

vector <int> primes;

void sieveErat(int n){
    bool arr[n + 1];
    for (int i = 0; i <= n; i++){
        arr[i] = true;
    }
    for (int i = 2; i * i <= n; i++){
        if (arr[i] == true){
            for (int j = i * i; j <= n; j += i){
                arr[j] = false;
            }
        }
    }
    for (int i = 2; i <= n ; i++){
        if (arr[i]){
            primes.push_back(i);
        }
    }
    for(int i = 0; primes[i] < n/2; i++){
        int diff = n - primes[i];
        if (binary_search(primes.begin(), primes.end(), diff)){
            cout << primes[i] << " " << diff;
            return;
        }
    }
}
int main(){
    int n; cin >> n;
    if (n == 4){
        cout << 2 << " " << 2;
        return 0;
    }
    sieveErat(n);
    return 0;
}