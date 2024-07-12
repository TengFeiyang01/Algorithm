#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 2e5 + 13;

struct ACTrie {
	int idx = 0;
	std::vector<std::array<int, 26>> ch;
	std::vector<int> cnt, fail;
	ACTrie(int n) {
		ch.resize(n);
		cnt.resize(n);
		fail.resize(n);
	}

	void insert(std::string s, int val = 1) {
		int p = 0;
		for (auto c : s) {
			c -= 'a';
			if (!ch[p][c]) ch[p][c] = ++idx;
			p = ch[p][c];
		}
		cnt[p] += val;
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
			cnt[u] += cnt[fail[u]];
			for (int i = 0; i < 26; ++i) {
				int v = ch[u][i];
				if (v) {
					// 有儿子 父节点帮助儿子建立回调边 
					fail[v] = ch[fail[u]][i];
					q.push(v);
				} else {
					ch[u][i] = ch[fail[u]][i];
				}
			}
		}
	}
};


void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size(), m;
    std::cin >> m;	

    ACTrie a(N), b(N);

    for (int i = 0; i < m; ++i) {
    	std::string t;
    	std::cin >> t;
    	a.insert(t, 1);
    	std::reverse(t.begin(), t.end());
    	b.insert(t, 1);
    }
    a.build();
    b.build();


    // f[i]表示以s[i]为后缀的字符的个数
    std::vector<i64> f(n + 1), g(n + 1);
    for (int i = 1, p = 0; i <= n; ++i) {
    	f[i] = a.cnt[p = a.ch[p][s[i - 1] - 'a']];
    }

    i64 ans = 0;
    // g[i]表示从s[i]开始字符串的个数
    for (int i = n, p = 0; i > 0; --i) {
    	ans += f[i - 1] * b.cnt[p = b.ch[p][s[i - 1] - 'a']];
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
