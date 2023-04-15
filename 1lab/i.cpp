#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string str; cin>>str;
    queue <int> k;
    queue <int> s;
    for (int i = 0 ; i < str.size(); i++){
        if (str[i] == 'K'){
            k.push(i);
        }
        else s.push(i);
    }
    while (!s.empty() and !k.empty()){
        if (s.front() > k.front()){
            k.push(k.front() + str.size());
            k.pop();
            s.pop();
        }
        else if (k.front() > s.front()){
            s.push(s.front() + str.size());
            k.pop();
            s.pop();
        }
    }
    if (!k.empty()){
        cout<<"KATSURAGI";
    }
    else if (!s.empty()){
        cout<<"SAKAYANAGI";
    }
    return 0;
}