#include <bits/stdc++.h>
 
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> L(n + 1);
    std::vector f(n + 1, std::vector<int>(25));
    std::vector g(n + 1, std::vector<i64>(25));
    for (int i = 2; i <= n; ++i) {
    	std::cin >> L[i];
    }
    //g[n][0] 从n走到左边所有点 2^0 = 1步
    f[n][0] = L[n]; g[n][0] = n - L[n];
   	for (int i = n - 1; i >= 2; --i) {
   		f[i][0] = std::min(f[i + 1][0], L[i]);
   		g[i][0] = i - f[i][0];
   	}
   	for (int j = 1; 1 << j <= n; ++j)
   		for (int i = (1 << j); i <= n; ++i) {
   			f[i][j] = f[f[i][j - 1]][j - 1];
   			g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1] + (1 << j - 1) * (f[i][j - 1] - f[i][j]);
   		}

   	auto get = [&](int x, int to) -> i64 {
   		if (L[x] <= to) return x - to;
   		i64 ans = x - L[x], step = 1;
   		x = L[x];
   		for (int i = 20; i >= 0; --i) {
   			if (f[x][i] >= to) {
   				ans += step * (x - f[x][i]) + g[x][i];
   				step += (1 << i);
   				x = f[x][i];
   			}
   		}
   		if (x > to) ans += step * (x - to) + x - to;
   		return ans;
   	};

   	std::cin >> m;
   	while (m--) {
   		int l, r, x;
   		std::cin >> l >> r >> x;
   		i64 fz = get(x, l) - get(x, r + 1), g = std::__gcd(fz, r - l + 1LL);
   		std::cout << fz / g << "/" << (r - l + 1) / g<< "\n";
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
