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
    int n, m;
    std::cin >> n;
    std::vector<PII> a(n << 1);
    for (int i = 0; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	a[i << 1] = {u, i << 1};
    	a[i << 1 | 1] = {v, i << 1 | 1};
    }

    std::sort(a.begin(), a.end());
    PII b[2][2];
    for (int i = 0; i < 2; ++i)
    	for (int j = 0; j < 2; ++j)
    		b[i][j] = {-1, -1};
    m = n;
    int ans = inf;
    std::vector<bool> st(n << 1);
    for (auto&[val, t] : a) {
    	int x = t & 1;
    	if (!st[t / 2]) m--;
    	st[t / 2] = 1;
    	std::swap(b[x][0], b[x][1]);
    	b[x][0] = {val, t};
    	for (int i = 0; i < 2; ++i) {
    		if (m || b[x ^ 1][i].second == -1 || b[x ^ 1][i].second == (t ^ 1)) continue;
    		ans = std::min(ans, val - b[x ^ 1][i].first);
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
