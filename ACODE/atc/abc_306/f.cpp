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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 2>> a(n * m);

    for (int i = 0, p = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[p][0];
    		a[p][1] = i;
            p++;
    	}
    }

    std::sort(a.begin(), a.end(), [&](auto x, auto y){
        return x[0] < y[0];
    });

    i64 ans = 0;
    Fenwick<int> f(n);
    int s = 0;

    for (int i = 0; i < n * m; ++i) {
    	int x = a[i][1];
        //sum是左闭右开
    	int pre = f.sum(x);  //[0, x - 1]
    	int cur = f.sum(x + 1);
    	ans += s - cur + 1LL * (n - x - 1) * (cur - pre + 1);
    	f.add(x, 1);
        s++;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
