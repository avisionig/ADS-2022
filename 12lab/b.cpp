#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> e[200005];



int fb(int x, int y, int n, int m) {
	vector<int> g(200005,1000000000);
	g[x] = 0;
	set <pair<int, int>> st;
	st.insert({g[x], x});
	while(!st.empty()) {
		int z = st.begin()->second;
		st.erase(st.begin());
		for (int i = 0; i < e[z].size(); i++) {
			if (g[e[z][i].first] > e[z][i].second + g[z]) {
				st.erase({g[e[z][i].first],e[z][i].first});
				g[e[z][i].first] = e[z][i].second + g[z];
				st.insert({g[e[z][i].first],e[z][i].first});
			}
		}
	}
	return g[y];
}

int main() {

    int m, n, a, b, c, d;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
        e[u].push_back({v,w});
		e[v].push_back({u, w});
	}
	cin >> a >> b >> c >> d;
	int ab = fb(a, b, n, m);
	int bc = fb(b, c, n, m);
	int cd = fb(c, d, n, m);

	int ac = fb(a, c, n ,m);
	int cb = fb(c, b, n, m);
	int bd = fb(b, d, n, m);

	if (ab + bc + cd >=1000000000 && ac + cb + bd >=1000000000) {
		cout << -1;
        return 0;
	}
	
    cout << min(ab + bc + cd, ac + cb + bd);
	return 0;
}