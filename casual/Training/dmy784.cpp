#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

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
    int n, q, tot = -1;
    std::cin >> n >> q;
    std::vector<int> a(n), l(n), r(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	l[u] = ++tot;
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u);
    	}
    	r[u] = tot;
    };
    dfs(0, -1);

    Fenwick<i64> c1(n << 1 | 1), c2(n << 1 | 1);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	c1.add(l[i], a[i]);
    	c2.add(l[i], a[i]);
    	c2.add(r[i] + 1, -a[i]);
    }

    for (int i = 0; i < q; ++i) {
    	int op, x, y;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> x >> y;
    		--x, y;
    		int d = y - a[x];
    		a[x] = y;
    		c1.add(l[x], d);
    		c2.add(l[x], d);
    		c2.add(r[x] + 1, -d);
    	} else {
    		int x;
    		std::cin >> x;
    		--x;
    		std::cout << c1.rangeSum(l[x], r[x] + 1) << " " << c2.sum(l[x] + 1) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
