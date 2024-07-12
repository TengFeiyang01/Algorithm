#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int ans[2000001]{0};
constexpr int N = 2e5 + 13;
int ch[N][26], ne[N * 26], idx = 0, cnt[N * 26], in[N * 26];

void insert(std::string s, int val) {
	int p = 0;
	for (auto c : s) {
		c -= 'a';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	cnt[val] = p;
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
				in[ne[v]]++;
				q.push(v);
			} else {
				// 没有儿子 自建转移边
				ch[u][i] = ch[ne[u]][i];
			}
		}
	}
}

// 只打标记 更新通过topo
void query(std::string &s) {
	for (int i = 0; auto c : s) {
		i = ch[i][c - 'a'];
		ans[i]++;
	}
}

void topo() {
	std::queue<int> q;
	for (int i = 1; i <= idx; ++i) {
		if (!in[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int v = ne[u];
		ans[v] += ans[u];
		if (--in[v] == 0) {
			q.push(v);
		}
	}
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
    	std::string str;
    	std::cin >> str;
    	insert(str, i);
    }
    build();
    std::string s;
    std::cin >> s;
    query(s);
    topo();
    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[cnt[i]] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
