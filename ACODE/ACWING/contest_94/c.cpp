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
const int N = 500 + 13;

int g[N][N]{0};

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j)
			std::cin >> g[i][j];
	std::vector<int> p(n);
	for (int &v : p) std::cin >> v;
	std::reverse(p.begin(), p.end());
	
	std::vector<long long> ans(n);

	int mp[N]{0};
	int j = n - 1;

	//Floyd最外层的k是每次新增的点 我们倒序加点即可

	for (int k : p) {
		long long cur = 0;
		mp[k] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
				if (mp[i] && mp[j]) 
					cur += g[i][j];
			}
		ans[j--] = cur;
	}
	for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
