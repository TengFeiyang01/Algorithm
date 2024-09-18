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
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

class unionfind {
private:
	std::vector<int> fa;
public:

	unionfind(int n) {
		fa.resize(n);
		iota(all(fa), 0);
	}

	int find(int x) {
		if (x != fa[x])
			return fa[x] = find(fa[x]);
		return fa[x];
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y)
			fa[x] = y;
	}
};

int head[N], idx;
struct e{
    int u, v, w;

    bool operator<(const e &b) const {
    	return w < b.w;
    }
}edge[N];

void solve() {
    int n, m;
    std::cin >> n >> m;
    unionfind uf(n + 1);
    for (int i = 0; i < m; ++i) {
    	auto&[u, v, w] = edge[i];
    	std::cin >> u >> v >> w;
    }

    std::sort(edge, edge + m);

    int ans = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
    	auto[u, v, w] = edge[i];
    	u = uf.find(u), v = uf.find(v);
    	if (u != v) {
    		cnt++;
    		uf.merge(u, v);
    		ans += w;
    	}
    }
    if (cnt < n - 1) std::cout << "impossible";
    else std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
