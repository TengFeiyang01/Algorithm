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
struct tp {
	int fi, fv, se;
};

const int N = 1e5 + 13;

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<int> g[n], st(n);
    for (int i = 0; i < m; ++i) {
    	int x;
    	std::cin >> x;
    	st[x - 1] = 1;
    }

    std::vector<tp> dis(n);

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	u--, v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    int mx1 = 0;
    //第一次dfs 得到所有点向下的最远怪物的最大距离和最小距离
    std::function<int(int, int)> dfs1 = [&](int u, int fa)->int{
    	int fi = -inf, fv = 0, se = -inf;
    	for (auto& v : g[u]) {
    		if (v != fa) {
    			int d = dfs1(v, u) + 1;
    			if (d > fi) {
    				se = fi;
    				fi = d;
    				fv = v;
    			} else if (d > se) {
    				se = d;
    			}
    		}
    	}
    	dis[u] = {fi, fv, se};
    	if (fi < 0 && st[u]) return 0;
    	return fi;
    };
    dfs1(0, -1);

    int ans = 0;
    //dDa表示的是从当前结点往上走碰到的最远的怪物的距离
    std::function<void(int, int, int)> dfs2 = [&](int u, int fa, int dFa) {
    	if (dFa > d) return;
    	auto[fi, fv, se] = dis[u];
    	if (fi <= d) ans++;
    	if (st[u] && dFa < 0) dFa = 0;
    	for (auto& v : g[u]) {
    		if (v != fa) {
    			if (v == fv) {
    				dfs2(v, u, std::max(dFa, se) + 1);
    			} else {
    				dfs2(v, u, std::max(dFa, fi) + 1);
    			}
    		}
    	}
    };
    dfs2(0, -1, -inf);
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
