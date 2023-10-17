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
    std::vector<int> g[n + 1];
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	g[u].emplace_back(v);
    	g[v].emplace_back(u);
    }
    std::vector<int> siz(n, 1);

    ll cnt1 = 0LL;
    std::function<void(int, int, ll)> dfs1 = [&](int u, int fa, ll d) {
    	cnt1 += d;
    	for (int v : g[u]) {
    		if (v != fa) {
    			dfs1(v, u, d + 1);
    			siz[u] += siz[v];
    		}
    	}
    };
    dfs1(1, 0, 0);
    ll ans = cnt1;
    int id = 1;

    std::function<void(int, int, ll)> dfs2 = [&](int u, int fa, ll cnt) {
    	if (cnt >= ans) {
    		id = u;
    		ans = cnt;
    	}
        //考虑从以u为根换到以v为根 cnt的变化量
        //显然 以v为根的子树所有的路径长度均减少了1（累计为：siz[v]） 出去以v为根的子树外的结点到v的距离都增加了1 (累计为：n - siz[v])
        //故总的cnt变化量为 cnt - siz[v] + n - siz[v] = cnt + n - 2 * siz[v] 
    	for (int v : g[u]) {
    		if (v != fa) {
    			dfs2(v, u, cnt + n - 2LL * siz[v]);
    		}
    	}
    };
    dfs2(1, 0, cnt1);

    std::cout << id;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
