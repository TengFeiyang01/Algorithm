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
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    int q;
    std::cin >> q;
    std::vector<int> ans(q);
    std::map<int, int> pos;
    std::vector<std::array<int, 3>> qry(q);
    for (int i = 0; i < q; ++i) {
    	int l, r;
        std::cin >> l >> r;
        --l, --r;
    	qry[i] = {r, l, i};
    }
    std::sort(qry.begin(), qry.end());
    int j = 0;

    Fenwick<int> tr(n);
    for (int i = 0; i < n; ++i) {
    	if (pos.count(a[i])) {
    		tr.add(pos[a[i]], -1);
    	}
    	pos[a[i]] = i;
    	tr.add(i, 1);
    	while (j < q and qry[j][0] <= i) {
    		auto [r, l, id] = qry[j]; 
    		ans[id] = tr.rangeSum(l, r + 1);
    		j++;
    	}
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
