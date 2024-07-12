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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    // 知道当前左侧有多少大于他的 
    Fenwick<int> tr(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	--a[i];
    }
    i64 ans = 0, res = 0;
    std::vector<int> ge(n), lo(n);
    for (int i = 0; i < n; ++i) {
    	ge[i] = tr.rangeSum(a[i], n);
    	lo[i] = tr.sum(a[i] + 1);
    	tr.add(a[i], 1);
    }
    tr.init(n);
   	for (int i = n - 1; i >= 0; --i) {
   		ans += ge[i] * 1LL * tr.rangeSum(a[i], n);
   		res += lo[i] * 1LL * tr.sum(a[i]);
        tr.add(a[i], 1);
   	}
   	std::cout << ans << " " << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
