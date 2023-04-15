#include <bits/stdc++.h>
using namespace std;
// struct Edge{
//     int v,u, cost;
// };
vector <int> v;
int find (int i) {
    if (v[i] == i){
        return i;
    }
    return v[i] = find (v[i]);
}

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (rand() & 1)
		swap (x, y);
	if (x != y)
		v[x] = y;
}

int main(){
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int c; cin >> c;
            edges.push_back(make_pair(c, make_pair(i, j)));
        }

    }
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
    long long sum = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++){
        int x = edges[i].second.first, y = edges[i].second.second, z = edges[i].first;
        if(find(x) != find(y)){
            sum += z;
            unite(x,y);
        }
    }
    cout << sum;
    return 0;
}