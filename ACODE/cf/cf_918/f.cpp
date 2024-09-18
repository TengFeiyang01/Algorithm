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
    std::vector<std::array<int, 2>> a(n);
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    	st.insert(a[i][0]);
    	st.insert(a[i][1]);
    }
    std::ranges::sort(a, [&](auto &x, auto &y){
    	if (x[0] != y[0]) {
    		return x[0] < y[0];
    	} 
    	return x[1] > y[1];
    });
    std::vector<int> b{st.begin(), st.end()};
    auto find = [&](int x) {
    	return std::ranges::lower_bound(b, x) - b.begin();
    };

    Fenwick<i64> tr(2 * n + 1);

    i64 ans = 0, m = b.size();
    for (auto [l, r] : a) {
    	l = find(l);
    	r = find(r);
    	ans += tr.rangeSum(r, 2 * n + 1);
        tr.add(r, 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
