#include <bits/stdc++.h>
using namespace std;
vector <int> ans;

int bfs(int a, int b){
    unordered_map <int, bool> mp;

    pair<int, int> temp = {b, 0};
    queue<pair<int,int>> q;
    int t = a;
    q.push(temp);
    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        if ( p.first == a){
            return p.second;
        }

        mp[p.first] = true;

        // if ( p.first / 2 == a || p.first + 1 == a){
        //     if (p.first / 2 == a){
        //         ans.push_back(p.first / 2);
        //          t *= 2;
        //     }
        //     else if (p.first + 1 == a){
        //         ans.push_back(p.first + 1);
        //         t -= 1;
        //     }
        //     return p.second + 1;
        // }

        if (p.first % 2 == 1){
            if (!mp[p.first / 2 + 1] and a < p.first){
                temp.first = (p.first + 1) / 2;
                temp.second = p.second + 1;
                temp.second = p.second + 1;
                ans.push_back(p.first);
                ans.push_back(p.first + 1);
                q.push(temp);
            }
        }
        else {
            if (!mp[p.first / 2 ] and a < p.first){
                temp.first = p.first / 2;
                temp.second = p.second + 1;
                ans.push_back(p.first );
                q.push(temp);
            }
        }
        if (!mp[p.first + 1] and a > p.first){
            temp.first = p.first + 1;
            temp.second = p.second + 1;
            ans.push_back(p.first);
            q.push(temp);
        }
    }
}
int main(){
    int a, b; cin >> a >> b;
    int cnt = bfs(a, b);
    if (ans.size() > cnt){
        cout << ans.size() << endl;
    }
    else {
        cout << cnt << endl;
    }
    if (ans.size() > 0){
        for(int i = ans.size() - 1 ; i >=0 ; i--){
            cout << ans[i] << " ";
        }
    }
    return 0;
}