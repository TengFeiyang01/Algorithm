#include <bits/stdc++.h>
 
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n];
    std::vector<int> color(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> color[i];
    }
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	x--, y--;
    	g[x].emplace_back(y);
    	g[y].emplace_back(x);
    }

    std::function<int(int, int, int, int)> dfs = [&](int u, int fa, int cnt, bool valid) {
    	if (color[u]) cnt++;
    	else cnt = 0;

    	if (cnt > m) valid = false;

    	int res = 0, sons = 0;
    	for (int v : g[u]) {
    		if (v != fa) {
    			sons++;
    			res += dfs(v, u, cnt, valid);
    		}
    	}
    	if (!sons and valid) res++;
    	return res;
    };


    std::cout << dfs(0, -1, 0, true);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
