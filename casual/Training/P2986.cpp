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
    std::vector<ll> c(n);
    std::vector<PII> g[n];
    ll tot = 0;
    for (ll &v : c) std::cin >> v, tot += v;
    auto siz = c;
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	g[u - 1].emplace_back(v - 1, w);
    	g[v - 1].emplace_back(u - 1, w);
    }
    ll cnt0 = 0;
    std::function<void(int, int, ll)> dfs1 = [&](int u, int fa, ll d) {
    	cnt0 += d * c[u];
    	for (auto[v, w] : g[u]) {
    		if (v != fa) {
    			dfs1(v, u, d + w);
    			siz[u] += siz[v];
    		}
    	}
    };

    dfs1(0, -1, 0);
    //tot 记录的是所有点权 cnt0记录的以0为根时总的不方便值
    ll ans = cnt0;
    std::function<void(int, int, ll)> dfs2 = [&](int u, int fa, ll cnt) {
    	if (cnt < ans) {
    		ans = cnt;
    	}
    	for (auto[v, w] : g[u]) {
    		if (v != fa) {
                //(tot - siz[v]) * 2为所有除v以外的结点的不方便值的增量，原本要到u 现在要到v 增加了(tot - siz[v]) * w;
                //-siz[v] * w是以v为根的所有结点的增量 原本要到u，现在只要到v 减少了 w * siz[v]
    			dfs2(v, u, cnt + (tot - siz[v] * 2LL) * w);
    		}
    	}
    };
    dfs2(0, -1, cnt0);
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
