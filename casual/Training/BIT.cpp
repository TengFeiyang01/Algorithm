#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

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
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	tr.add(i, a[i]);
    }

    for (int i = 0; i < q; ++i) {
    	i64 op, x, d, s;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> x >> d;
    		tr.add(x - 1, d - a[x - 1]);
    		a[x - 1] = d;
    	} else {
    		std::cin >> s;
    		int l = 0, r = n + 1;
    		while (l < r) {
    			int mid = l + r + 1 >> 1;
    			if (tr.sum(mid) <= s) {
    				l = mid;
    			} else {
    				r = mid - 1;
    			}
    		}
    		std::cout << l  << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
