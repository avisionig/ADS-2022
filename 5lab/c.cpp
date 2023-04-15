#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, x; cin >> n >> x;
    priority_queue <long> pq;
    for (int i = 0; i < n;i++){
        cin >> a;
        pq.push(a);
    }
    long sum = 0, temp;
    for(int i = 0; i < x; i++){
        temp = pq.top();
        pq.pop();
        sum += temp;
        pq.push(temp - 1);
    }
    cout << sum;
    return 0;
}