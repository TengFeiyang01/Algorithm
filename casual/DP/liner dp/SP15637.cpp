#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	while (std::cin >> n, n) {
		std::vector<int> s(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> s[i];
		}
		i64 dp[s[0] + 1][s[1] + 1][s[2] + 1][s[3] + 1][s[4] + 1];
		dp[0][0][0][0][0] = 1;
		for (int a = 0; a <= s[0]; ++a)
			for (int b = 0; b <= s[1]; ++b)
				for (int c = 0; c <= s[2]; ++c)
					for (int d = 0; d <= s[3]; ++d)
						for (int e = 0; e <= s[4]; ++e) {
							if (a < s[0]) dp[a + 1][b][c][d][e] += dp[a][b][c][d][e];
							if (b < s[1] and b < a) dp[a][b + 1][c][d][e] += dp[a][b][c][d][e];
							if (c < s[2] and c < b) dp[a][b][c + 1][d][e] += dp[a][b][c][d][e];
							if (d < s[3] and d < c) dp[a][b][c][d + 1][e] += dp[a][b][c][d][e];
							if (e < s[4] and e < d) dp[a][b][c][d][e + 1] += dp[a][b][c][d][e];
						}
		std::cout << dp[s[0]][s[1]][s[2]][s[3]][s[3]] << "\n";
	}    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
