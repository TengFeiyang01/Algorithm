#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<int> t(n << 1 | 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> t[i];
    	t[i + n] = t[i];
    }
    // mx: 区间最大值 max{tj-j}
    // mi: 区间最小值 min{i+max{tj-j}}
    std::vector<int> mx(8 << std::__lg(n)), mi(8 << std::__lg(n));
    std::function<int(int, int, int, int)> dfs = [&](int o, int l, int r, int mrs) {
    	if (l == r) return l + std::max(mx[o], mrs);
    	int mid = l + r >> 1;
    	if (mrs >= mx[o << 1 | 1]) {
    		return std::min(mid + 1 + mrs, dfs(o << 1, l, mid, mrs));
    	}
    	return std::min(mi[o], dfs(o << 1 | 1, mid + 1, r, mrs));
    };

    auto pull = [&](int o, int l, int r) {
    	int mid = l + r >> 1;
    	mx[o] = std::max(mx[o << 1], mx[o << 1 | 1]);
    	mi[o] = dfs(o << 1, l, mid, mx[o << 1 | 1]);
    };

    std::function<void(int, int, int)> build = [&](int o, int l, int r) {
    	if (l == r) {
    		mx[o] = t[l] - l;
    		mi[o] = t[l];
    		return;
    	}
    	int mid = l + r >> 1;
    	build(o << 1, l, mid);
    	build(o << 1 | 1, mid + 1, r);
    	pull(o, l, r);
    };

    std::function<void(int, int, int, int, int)> modify = [&](int o, int l, int r, int x, int t) {
    	if (l == r) {
    		mx[o] = t - l;
    		mi[o] = t;
    		return;
    	}
    	int mid = l + r >> 1;
    	if (x <= mid) modify(o << 1, l, mid, x, t);
    	else modify(o << 1 | 1, mid + 1, r, x, t);
    	pull(o, l, r);
    };

    build(1, 1, n << 1);
    int last;
    std::cout << (last = mi[1] + n - 1) << "\n";
    while (m--) {
    	int x, y;
    	std::cin >> x >> y;
    	if (p) {
    		x ^= last;
    		y ^= last;
    	}
    	modify(1, 1, n << 1, x, y);
    	modify(1, 1, n << 1, x + n, y);
    	std::cout << (last = mi[1] + n - 1) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
