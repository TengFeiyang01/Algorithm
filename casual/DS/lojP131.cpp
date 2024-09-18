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
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = n - 1; i > 0; --i) {
    	a[i] -= a[i - 1];
    }

    Fenwick<i64> tr(n);
    for (int i = 0; i < n; ++i) {
    	tr.add(i, a[i]);
    }
    for (int i = 0; i < q; ++i) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		i64 l, r, x;
    		std::cin >> l >> r >> x;
    		--l;
    		tr.add(l, x);
	    	tr.add(r, -x);
    	} else {
    		int x;
    		std::cin >> x;
    		std::cout << tr.sum(x) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
