#include <bits/stdc++.h>
 
using namespace std;
 

int main() {
	int n; cin >> n;
    int g[502][502], x[502];
    bool check[502];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for(int k = 1; k <= n; k++) {
        check[x[k]] = true;
        int tmp = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) { 
                g[i][j] = min(g[i][j], g[i][x[k]] + g[x[k]][j]);
                if(check[i] && check[j]) {
                    tmp = max(g[i][j], tmp);
                }
            }
        }
        cout << tmp << endl;
    }

	return 0;
}
