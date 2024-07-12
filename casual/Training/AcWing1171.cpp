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
int n, m;
int fa[N], dist[N]{0};
std::vector g(n, std::vector<PII>());

void solve() {
	std::cin >> n;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int x, y, k;
		std::cin >> x >> y >> k;
		x--, y--;
		g[x].emplace_back(y, k);
		g[y].emplace_back(x, k);
	}

	
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
