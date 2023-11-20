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
const int N = 99;

void solve() {
	int n, m;
    std::cin >> n >> m;
    std::vector<int> minv(N), mins(N), R(N), H(N);
    for (int i = 1; i <= m; ++i) {
    	minv[i] = minv[i - 1] + i * i * i;
    	mins[i] = mins[i - 1] + i * i * 2;
    }
    R[m + 1] = H[m + 1] = inf;

    int ans = inf;
    std::function<void(int, int, int)> dfs = [&](int u, int v, int s) {
    	if (v + minv[u] > n) return;
    	if (s + mins[u] >= ans) return;
    	if (s + 2 * (n - v) / R[u + 1] >= ans) return;

    	if (u == 0) {
    		if (v == n) ans = s;
            return;
    	}

    	for (int r = std::min(R[u + 1] - 1, int(std::sqrt(n - v))); r >= u; --r) 
    		for (int h = std::min(H[u + 1] - 1, (n - v) / r / r); h >= u; --h) {
    			int t = 0;
    			if (u == m) t = r * r;
    			R[u] = r, H[u] = h;
    			dfs(u - 1, v + r * r * h, s + 2 * r * h + t);
    		}

    };
    dfs(m, 0, 0);
    if (ans == inf) ans = 0;

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
