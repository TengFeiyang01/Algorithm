#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 7000;
constexpr int mod = 10007;

int ch[N][26], fail[N], cnt[N], idx = 0;

void insert(std::string s) {
	int p = 0;
	for (auto c : s) {
		c -= 'A';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	cnt[p] = 1;
}


void build() {
	std::queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (ch[0][i]) {
			q.push(ch[0][i]);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		// 当结点保存所有的转移结点 
		cnt[u] |= cnt[fail[u]];
		for (int i = 0; i < 26; ++i) {
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

int qpow(int x, int y) {
    int res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
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

    std::vector dp(m + 1, std::vector<int>(N));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j <= idx; ++j) {
    		for (int k = 0; k < 26; ++k) {
    			if (!cnt[ch[j][k]]) {
    				dp[i + 1][ch[j][k]] = (dp[i][j] + dp[i + 1][ch[j][k]]) % mod;
    			}
    		}
    	}
    }
    int ans = qpow(26, m);
    for (int i = 0; i <= idx; ++i) {
    	ans = (ans - dp[m][i] + mod) % mod;
    }
    std::cout << ans % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
