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
    std::vector<i64> a(n), ans(q);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::array<int, 3>> queries(q);
    for (int i = 0; i < q; ++i) {
    	std::cin >> queries[i][1] >> queries[i][0];
    	queries[i][2] = i;
    }
    std::sort(queries.begin(), queries.end());

    std::vector<i64> last(n + 1, -1);

    Fenwick<i64> tr(n + 1);
    int j = 0;
    for (int i = 0; i < q; ++i) {
    	int l = queries[i][1], r = queries[i][0], id = queries[i][2];
        --l;
    	while (j < r) {
    		if (last[a[j]] != -1) {
    			tr.add(last[a[j]], -a[j]);
    		}
    		tr.add(j, a[j]);
    		last[a[j]] = j;
            j++;
    	}
    	ans[id] = tr.rangeSum(l, r);
    }
    for (int i = 0; i < q; ++i) {
    	std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
