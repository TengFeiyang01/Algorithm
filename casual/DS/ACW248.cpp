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
    Fenwick<i64> tr(n);
    for (int i = 0, x, old = 0; i < n; ++i) {
    	std::cin >> x;
    	tr.add(i, x - old);
    	old = x;
    }
    for (int i = 0; i < q; ++i) {
    	char op;
    	std::cin >> op;
    	if (op == 'Q') {
    		int x;
    		std::cin >> x;
    		std::cout << tr.sum(x) << "\n";
    	} else {
    		int l, r, d;
    		std::cin >> l >> r >> d;
    		--l;
    		tr.add(l, d);
    		tr.add(r, -d);
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
