#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 4e3 + 13;
int d[N]{0};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::unordered_map<int, int> g[N];
    std::vector<PII> edges;
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	g[x][y]++;
    	g[y][x]++;
    	d[x]++;
    	d[y]++;
    	edges.emplace_back(x, y);
    }
    int ans = inf;

    for (auto[x, y] : edges) {
    	for (int z = 1; z <= n; ++z) {
    		if (z == x or z == y) continue;
    		if (g[x][z] and g[y][z]) {
    			ans = std::min(ans, d[x] + d[y] + d[z] - 6);
    		}
    	}
    }

    if (ans == inf ) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
