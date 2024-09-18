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
    int n, W;
    std::cin >> n >> W;
    std::vector<int> a(n);
    for (int &v : a) std::cin >> v;
    //搜索顺序优化
    std::sort(all(a), std::greater<int>());
	int ans = n;
	std::vector<long> w(n);
	std::function<void(int, int)> dfs = [&](int u, int cnt) {
		if (cnt >= ans) return;	//最优性剪枝
		if (u == n) ans = cnt;
		for (int i = 0; i < cnt; ++i)
			if (w[i] + a[u] <= W) {
				w[i] += a[u];
				dfs(u + 1, cnt);
				w[i] -= a[u];
			}
		w[cnt] = a[u];
		dfs(u + 1, cnt + 1);
		w[cnt] = 0;
	};
	dfs(0, 0);
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}