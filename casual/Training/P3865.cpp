#include <bits/stdc++.h>
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector ST(n + 1, std::vector<int>(26));
    for (int i = 1; i <= n; ++i) {
    	std::cin >> ST[i][0];
    }
    for (int j = 1; 1 << j <= n; ++j)
    	for (int i = 1; i + (1 << j) - 1 <= n; ++i)
    		ST[i][j] = std::max(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);

    while (m--) {
    	int l, r;
    	std::cin >> l >> r;
    	int k = log2(r - l + 1);
    	std::cout << std::max(ST[l][k], ST[r - (1 << k) + 1][k]) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
  