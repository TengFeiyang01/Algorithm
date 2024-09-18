#include <bits/stdc++.h>
 
using ll = long long;
const int N = 11;
using bs = std::bitset<N>;

void solve() {
    int n, m;
    std::cin >> m >> n;
    std::vector a(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) std::cin >> a[i][m];
    for (int j = 0; j < m; ++j)
    	for (int i = 0; i < n; ++i) 
    		std::cin >> a[i][j];
    std::sort(a.begin(), a.end());
    std::vector<bs> lower(n);
    for (int i = 0; i < n; ++i) lower[i].set();
    std::vector<int> inds(n);


	std::iota(inds.begin(), inds.end(), 0);
	for (int i = 0; i < m; ++i) {
		std::sort(inds.begin(), inds.end(), [&](int x, int y){
			return a[x][i] < a[y][i];
		});

		//通过双指针得出能转移到j的集合
		int p = 0;
		bs cur = 0;
		for (int j = 0; j < n; ++j) {
			while (a[inds[p]][i] < a[inds[j]][i]) cur.set(inds[p++], 1);
			lower[inds[j]] &= cur;
		}
	}

	std::vector<ll> dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = a[i][m];
		for (int j = 0; j < i; ++j) {
			if (lower[i][j]) dp[i] = std::max(dp[i], dp[j] + a[i][m]);
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
