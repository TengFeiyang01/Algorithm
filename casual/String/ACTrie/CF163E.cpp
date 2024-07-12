#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int N = 1e6 + 5;
int ch[N][26], fail[N], idx = 0, ed[N], siz[N], dfn[N], tot = 0, st[N];
std::vector<int> adj[N];

void insert(std::string s, int val) {
	int p = 0;
	for (auto x : s) {
		int c = x - 'a';
		if (!ch[p][c]) ch[p][c] = ++idx;
		p = ch[p][c];
	}
	ed[val] = p;
}

void build() {
	std::queue<int> q;
	for (int i = 0; i < 26; ++i) {
		if (ch[0][i]) q.push(ch[0][i]);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		adj[fail[u]].push_back(u);
		for (int i = 0; i < 26; ++i) {
			int v = ch[u][i];
			if (v) {
				// 有儿子 爹帮儿子建边
				fail[v] = ch[fail[u]][i];
				q.push(v);
			} else {
				// 没有儿子 自建转移边
				ch[u][i] = ch[fail[u]][i];
			}
		}
	}
}


template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};


void dfs(int u) {
	siz[u] = 1;
	dfn[u] = ++tot;
	for (auto v : adj[u]) {
		dfs(v);
		siz[u] += siz[v];
	}
}

void solve() {
	int n, k;
	std::string s;
	std::cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		std::cin >> s;
		insert(s, i);
		st[i] = 1;
	}

	build();

	dfs(0);
	Fenwick<int> tr(tot + 1);

	auto add = [&](int x, int v) {
		tr.add(dfn[ed[x]], v);			
		tr.add(dfn[ed[x]] + siz[ed[x]], -v);	
	};

	for (int i = 1; i <= k; ++i) {
		add(i, 1);
	}
	for (int i = 1, k; i <= n; ++i) {
		char op;
		std::cin >> op;
		if (op == '-') {
			std::cin >> k;
			if (st[k]) {
				add(k, -1);
				st[k] = 0;
			}
		} else if (op == '+') {
			std::cin >> k;
			if (!st[k]) {
				add(k, 1);
				st[k] = 1;
			}
		} else {
			i64 ans = 0, p = 0;
			std::cin >> s;
			for (auto c : s) {
				ans += tr.sum(dfn[p = ch[p][c - 'a']] + 1);
			}
			std::cout << ans << "\n";
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
