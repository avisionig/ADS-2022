#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

int n;
vector<Edge> edges;

void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }

        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v + 1 << ' ';
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            Edge e;
            e.a = j;
            e.b =i;
            e.cost = a;
            edges.push_back(e);
        }
    }
    solve();
}