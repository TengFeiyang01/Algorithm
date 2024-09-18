#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 1e5 + 5;
const int S = 26;

//https://www.cnblogs.com/alex-wei/p/Common_String_Theory_Theory_automaton_related.html

int stc[N], top, node, ed[N], ch[N][S], n;
int dn, fail[N], dfn[N], sz[N], ans[N];

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

void solve() {
    std::string s;
    int m;
    std::cin >> s >> m;

    for (int p = 0; auto c : s) {
    	if (c == 'P') {
            // ed 表示的是当前位置是否是末尾
    		ed[++n] = p;
    		continue;
    	}
    	if (c == 'B') {
            // stc 存储访问的的结点
    		p = stc[--top];
    		continue;
    	}
    	if (!ch[p][c - 'a']) {
    		ch[p][c - 'a'] = ++node;
    	}
    	stc[++top] = p = ch[p][c - 'a'];
    }

    std::vector<std::vector<int>> adj(N);
    std::vector<std::vector<std::pair<int, int>>> qry(N);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	qry[y].emplace_back(x, i);
    }

    std::queue<int> q;
    for (int i = 0; i < S; ++i) {
    	if (ch[0][i]) {
    		q.push(ch[0][i]);
    	}
    }
    while (!q.empty()) {
    	int u = q.front(); q.pop();
        // 建立 fail 树， fail[u]一定是u代表结点的后缀
    	adj[fail[u]].emplace_back(u);

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
    std::vector<int> ans(m);
    std::function<void(int)> dfs = [&](int u) {
    	sz[u] = 1;
    	dfn[u] = ++dn;
    	for (auto v : adj[u]) {
    		dfs(v);
    		sz[u] += sz[v];
    	}
    };

    Fenwick<int> tr(N);
    dfs(0), top = 0;
    for (int p = 0, j = 0; auto c : s) {
    	if (c == 'P') {
    		for (auto [x, id] : qry[++j]) {
    			int q = ed[x];
    			ans[id] = tr.rangeSum(dfn[q], dfn[q] + sz[q]);
    		} 
    	} else if (c == 'B') {
    		tr.add(dfn[p], -1);
    		p = stc[--top];
    	} else {
   			stc[++top] = p = ch[p][c - 'a'];
    		tr.add(dfn[p], 1);
    	}
    }
    for (int i = 0; i < m; ++i) {
    	std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
