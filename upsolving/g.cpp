#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    deque <int> dq;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        if (dq.empty()){
            dq.push_front(a);
        }
        else {
            while(!dq.empty() and a - dq.back() > 3000){
                dq.pop_back();
            }   
            dq.push_front(a);
        }
        cout << dq.size() << " ";
    }
    return 0;

}