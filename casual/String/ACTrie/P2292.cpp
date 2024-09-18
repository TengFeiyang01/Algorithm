#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 400, M = 1e6 + 13;

int idx = 0, ch[N][26], fail[N], cnt[N], g[M];

void insert(std::string s, int val) {
	int p = 0;
	for (auto c : s) {
		c -= 'a';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	// g[p] 存储的是p结点为止的 所有串的终止的长度
	g[p] |= 1 << val - 1;
	cnt[p] = val;
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
		// fail[u]中的串是u结点对应的串的后缀 故或起来
		g[u] |= g[fail[u]];
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

void solve() {
	int n, m;
	std::string s;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		insert(s, int(s.size()));
	}
	build();
	for (int i = 0; i < m; ++i) {
		int ans = 0;
		std::cin >> s;
		for (int u = 0, i = 1, now = 1; auto c : s) {
			u = ch[u][c - 'a'];
			// now 存的是最近的20个dp数组的值 滚动
			if (now & g[u]) now = now << 1 | 1, ans = i;
			else now = now << 1;
			i++;
		}
		std::cout << ans << "\n";
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
