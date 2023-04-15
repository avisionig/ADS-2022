#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long a;
    priority_queue<long, vector<long>, greater<long>>  pq;
    for(int i = 0; i < n; i++){
        cin >> a;
        pq.push(a);
    }
    long sum1= 0, temp, sum = 0;
    while(pq.size() != 1){
        temp = pq.top();
        pq.pop();
        sum = temp + pq.top();
        sum1 += sum;
        pq.push(temp + pq.top());
        pq.pop();
    }
    cout << sum1;
}