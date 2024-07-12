#include <bits/stdc++.h>


#define sz(x) int((x).size())
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
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> g[n];
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	x--, y--;
    	g[x].emplace_back(y, i);
    	g[y].emplace_back(x, i);
    }
    std::vector<bool> cut(n);
    std::vector<int> siz(n);

    std::function<bool(int, int)> dfs = [&](int u, int fa) ->bool {
    	siz[u] = 1;
    	for (auto[v, id] : g[u]) {
    		if (v == fa) continue;
    		if (!dfs(v, u)) return false;
    		if (siz[v] == 3) cut[id] = true;
    		else {
    			siz[u] += siz[v];
    		}
    	}
    	return siz[u] <= 3;
    };

    if (!dfs(0, -1) or siz[0] != 3) {
    	std::cout << "-1\n";
    	return;
    }
    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
    	if (cut[i]) {
    		ans.push_back(i + 1);
    	}
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
    	std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
