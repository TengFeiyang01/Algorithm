#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 7000;
constexpr int mod = 10007;
constexpr int S = 3;
int ch[N][S], fail[N], cnt[N], idx = 0;

void insert(std::string s) {
	int p = 0;
	for (auto c : s) {
		c -= 'A';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	cnt[p]++;
}


void build() {
	std::queue<int> q;
	for (int i = 0; i < S; ++i) {
		if (ch[0][i]) {
			q.push(ch[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		// 每个点的贡献是所有的串的贡献
		cnt[u] += cnt[fail[u]];
		// 当结点保存所有的转移结点 
		for (int i = 0; i < S; ++i) {
			int v = ch[u][i];
			if (v) {
				fail[v] = ch[fail[u]][i];
				q.push(v);
			} else {
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	insert(s);
    }
    build();

    std::vector dp(m + 1, std::vector<i64>(idx + 1, -inf));
    dp[0][0] = 0;

    i64 ans = 0;
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j <= idx; ++j) {
    		for (int k = 0; k < S; ++k) {
    			dp[i + 1][ch[j][k]] = std::max(dp[i + 1][ch[j][k]], dp[i][j] + cnt[ch[j][k]]);
    			ans = std::max(ans, dp[i + 1][ch[j][k]]);
    		}
    	}
    }

    std::cout << ans % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
