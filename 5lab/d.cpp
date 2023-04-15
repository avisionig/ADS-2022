#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, m; cin >> n >> m;
    priority_queue<long, vector<long>, greater<long>>  pq;
    for (int i = 0; i < n;i++){
        cin >> a;
        pq.push(a);
    }
    int cnt = 0;
    long temp;
    while(pq.size() > 1){
        if (pq.top() >= m){
            break;
        }
        temp = pq.top();
        pq.pop();
        temp = temp + (pq.top() * 2);
        pq.pop();
        pq.push(temp);
        cnt++;
    }
    if (pq.top() < m){
        cout << -1;
    }
    else cout << cnt;
    return 0;
}