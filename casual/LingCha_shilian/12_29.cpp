#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m;
//离一个点u最远的点一定是树的直径的两个端点；
//https://zhuanlan.zhihu.com/p/561119073
std::vector<int> v[N];
int dist, ma, l, r, depth[N], fa[N][25];

//最近公共祖先
int lca(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);
	for (int k = 20; k >= 0; --k)
		if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
	if (a == b) return a;
	for (int k = 20; k >= 0; --k) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}

void dfs1(int u, int father, int d) {
	if (d > ma) {
		ma = d;
		l = u;
	}
	for (auto x : v[u]) {
		if (x == father) continue;
		dfs1(x, u, d + 1);
	}
}

void dfs2(int u, int father, int d) {
	if (d > ma) {
		ma = d;
		r = u;
	}
	for (auto x : v[u]) {
		if (x == father) continue;
		dfs2(x, u, d + 1);
	}
}

int dis(int x, int y) {
	return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

void RMQ(int u, int father) {
	depth[u] = depth[father] + 1;
	fa[u][0] = father;
	for (int k = 1; k <= 20; ++k)
		fa[u][k] = fa[fa[u][k - 1]][k - 1];
	for (auto x : v[u]) {
		if (x == father) continue;
		RMQ(x ,u);
	}
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    dfs1(1, 0, 0);
    ma = 0;
    //找直径
    dfs2(l, 0, 0);
    RMQ(1, 0);
    int m;
    std::cin >> m;

    while (m--) {
    	int u, k;
    	std::cin >> u >> k;
    	int cur;;
    	if (dis(u, l) >= dis(u, r)) cur = l;
    	else cur = r;
    	if (dis(u, cur) < k) std::cout << "-1\n";
    	else {
    		if (depth[u] - depth[lca(u, cur)] >= k) { //左边
    			for (int i = 20; i >= 0; --i) {
    				if (k >= (1 << i)) {
    					k -= (1 << i);
    					u = fa[u][i];
    				}
    			}
    			std::cout << u << "\n";
    		} else {
    			k = dis(u, cur) - k;
    			for (int i = 20; i >= 0; --i) {
    				if (k >= (1 << i)) {
    					k -= (1 << i);
    					cur = fa[cur][i];
    				}
    			}
    			std::cout << cur << "\n";
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
