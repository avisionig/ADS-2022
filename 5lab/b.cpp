#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a; cin >> n;
    priority_queue <long> pq;
    for (int i = 0; i < n;i++){
        cin >> a;
        pq.push(a);
    }
    long x, y;
    while (pq.size() > 1){
        x = pq.top();
        pq.pop();
        if (x == pq.top()){
            pq.pop();
            continue;
        }
        y = x - pq.top();
        pq.pop();
        pq.push(y);

    }
    if (pq.size() == 1){
        cout << pq.top();
    }
    else cout << 0;
    return 0;
}