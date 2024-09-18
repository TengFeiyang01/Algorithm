#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e6 + 13;
int ch[N][26], ne[N], idx = 0, cnt[N << 2];

void insert(std::string s, int val) {
	int p = 0;
	for (auto c : s) {
		c -= 'a';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	cnt[p] = val;
}

void build() {
	std::queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (ch[0][i]) q.push(ch[0][i]);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++i) {
			int v = ch[u][i];
			if (v) {
				// 有儿子 爹帮儿子建边
				ne[v] = ch[ne[u]][i];
				q.push(v);
			} else {
				// 没有儿子 自建转移边
				ch[u][i] = ch[ne[u]][i];
			}
		}
	}
}

int query(std::string s) {
	int ans = 0;
	for (int j = 0, i = 0; auto c : s) {
		i = ch[i][c - 'a'];
		for (int j = i; j and ~cnt[j]; j = ne[j]) {
			ans += cnt[j];
			// 防止多次计算
			cnt[j] = -1;
		}
	}
	return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<std::string, int> hash;
    for (int i = 0; i < n; ++i) {
    	std::string t;
    	std::cin >> t;
    	hash[t]++;
    }
    for (auto [s, val] : hash) {
    	insert(s, val);
    }
    build();
    std::string s;
    std::cin >> s;
    std::cout << query(s) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
