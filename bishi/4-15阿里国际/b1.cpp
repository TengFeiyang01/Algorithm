#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 1e5 + 13;
using namespace std;
int n, ans = N;
vector<vector<int>> adj(N);

int dfs(int u, int fa) {
   	int s = 1, mx = 0, mn = n;
	
	for (auto v : adj[u]) {
		if (v != fa) {
			int x = dfs(v, u);
			s += x;
			mx = std::max(mx, x);
			mn = std::min(mn, x);
		}
	}

	mx = max(mx, n - s);
	mn = min(mn, n - s);
	if (s > 1) {
    	ans = min(ans, mx - mn);
	}
	return s;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
