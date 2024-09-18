#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
std::vector<int> ans;

struct ACTrie {
	int idx = 0;
	std::vector<std::array<int, 26>> ch;
	std::vector<int> cnt, fail;
	ACTrie(int n) {
		ch.resize(n * 20);
		cnt.resize(n * 50);
		fail.resize(n * 50);
	}

	void insert(std::string s, int val = 0) {
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
			if (ch[0][i]) {
				q.push(ch[0][i]);
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
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

	void query(std::string s) {
		for (int i = 0, j = 0; auto c : s) {
			i = ch[i][c - 'a'];
			for (j = i; j; j = fail[j]) {
				ans[cnt[j]]++;
			}
		}
	}
};

void solve() {
    int n;
    while (std::cin >> n, n) {
	    ACTrie acm(n * 100);
	    std::vector<std::string> S(n);
	    for (int i = 0; i < n; ++i) {
	    	std::cin >> S[i];
	    	acm.insert(S[i], i + 1);
	    }
	    acm.build();
	    ans.assign(n + 1, 0);
	    std::string s;
	    std::cin >> s;
	    acm.query(s);
	    int tmp = 0;
	    for (int i = 1; i <= n; ++i) {
	    	if (ans[i] > tmp) {
	    		tmp = ans[i];
	    	}
	    }
	    
	    std::cout << tmp << "\n";
	    for (int i = 1; i <= n; ++i) {
	    	if (ans[i] == tmp) {
	    		std::cout << S[i - 1] << "\n";
	    	}
	    }
	}


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
