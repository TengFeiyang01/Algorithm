#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    std::vector<T> b;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    	b.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
            b[i - 1] += 1LL * v * (x + 1);
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += 1LL * (x + 1) * a[i - 1] - b[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);

    Fenwick<i64> tr(n + 2);

    int tot = 0;
    for (int i = 0, last = 0, x; i < n; ++i) {
    	std::cin >> x;
    	tr.add(i, x - last);
    	last = x;
    }

    for (int i = 0; i < m; ++i) {
    	i64 op, x, l, r, y;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> l >> r >> x;
    		tr.add(l - 1, x);
    		tr.add(r, -x);
    	} else if (op == 2) {
    		std::cin >> x;
    		tot += x;
    	} else if (op == 3) {
    		std::cin >> x;
    		tot -= x;
    	} else if (op == 4) {
    		std::cin >> l >> r;
    		std::cout << tr.rangeSum(l - 1, r) + (x == 1) * tot << "\n";
    	} else {
    		std::cout << tr.sum(1) + tot << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}