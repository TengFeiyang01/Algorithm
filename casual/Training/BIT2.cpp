#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

template <typename T>
struct Fenwick {
    int n, m;
    std::vector<std::vector<T>> a;
    
    Fenwick(int n = 0, int m = 0) {
        init(n, m);
    }
    
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        a.assign(n, std::vector<T>());
        for (int i = 0; i < n; ++i) 
            a[i].assign(m, T());
    }
    
    void add(int x, int y, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                a[i - 1][j - 1] += v;
            }
        }
    }
    
    T sum(int x, int y) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans += a[i - 1][j - 1];
            }
        }
        return ans;
    }
};

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    Fenwick<i64> tr(n, m);
    std::vector<std::vector<i64>> a(n, std::vector<i64>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            tr.add(i, j, a[i][j]);
        }
    }


    for (int i = 0; i < q; ++i) {
    	i64 op, x, y, d;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> x >> y >> d;
    		tr.add(x - 1, y - 1, d - a[x - 1][y - 1]);
    		a[x - 1][y - 1] = d;
    	} else {
            std::cin >> x >> y;
            std::cout << tr.sum(x, y) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
