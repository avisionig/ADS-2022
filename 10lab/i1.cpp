#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector <vector <int> > g;
vector <int> vis;
stack <int> ans;

bool dfs(int i) {
    vis[i] = 1;
    for(int j = 0; j < g[i].size(); j++) {
        if(vis[g[i][j]] == 0) {
            dfs(g[i][j]);
        }
        else if(vis[g[i][j]] == 1) return false;
    }
    vis[i] = 2;
    ans.push(i);
    return true;
}

int main() {
    int n, m;cin >> n >> m;
    int test[n];

    g = vector <vector <int> >(n);
    vis = vector <int> (n, 0);

    for(int i = 0; i < n; i++) {
        test[i] = -1;
    }  

    for(int i = 0;i < m; i++){
        int x, y; cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        test[y] = x;
    }

    queue <int> q;
    for(int i = 0; i < n; i++) {
        if(test[i] == -1) q.push(i);
    }

    while(!q.empty()) {
        if(!dfs(q.front())) {
            cout << "Impossible\n";
            return 0;
        }
 
        q.pop();
    }

    if(ans.size() == n) {
        cout << "Possible\n";
    }
    else {
        cout << "Impossible\n";
        return 0;
    }
    while(!ans.empty()) {
        cout << ans.top() + 1 << " ";
        ans.pop();
    }
    return 0;
}