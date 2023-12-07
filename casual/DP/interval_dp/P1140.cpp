#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int tab[5][5]= {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
};

void solve() {
 	int n, m;
 	std::string s, t;
 	std::cin >> n >> s >> m >> t;
 	std::vector<int> a(n + 1), b(m + 1);

 	for (int i = 0; i < n; ++i) {
 		if (s[i] == 'A') a[i + 1] = 0;
 		else if (s[i] == 'C') a[i + 1] = 1;
 		else if (s[i] == 'G') a[i + 1] = 2;
 		else if (s[i] == 'T') a[i + 1] = 3;
 	}
  	for (int i = 0; i < m; ++i) {
 		if (t[i] == 'A') b[i + 1] = 0;
 		else if (t[i] == 'C') b[i + 1] = 1;
 		else if (t[i] == 'G') b[i + 1] = 2;
 		else if (t[i] == 'T') b[i + 1] = 3;
 	}

 	std::vector dp(n + 1, std::vector(m + 1, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
 		dp[i][0] = tab[a[i]][4] + dp[i - 1][0];
 	}
 	for (int i = 1; i <= m; ++i) {
 		dp[0][i] = tab[b[i]][4] + dp[0][i - 1];
 	}
 	for (int i = 1; i <= n; ++i) {
 		for (int j = 1; j <= m; ++j) {
 			dp[i][j] = std::max({dp[i - 1][j - 1] + tab[a[i]][b[j]], dp[i][j - 1] + tab[b[j]][4], dp[i - 1][j] + tab[a[i]][4]});
 		}
 	}
 	std::cout << dp[n][m];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
