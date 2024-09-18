#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<i64> tr(4 << std::__lg(n)), mx(4 << std::__lg(n));

    auto pull = [&](int o) {
    	tr[o] = tr[o << 1] + tr[o << 1 | 1];
    	mx[o] = std::max(mx[o << 1], mx[o << 1 | 1]);
    };

    std::function<void(int, int, int)> build = [&](int o, int l, int r) {
    	if (l == r) {
    		tr[o] = mx[o] = a[l - 1];
    		return;
    	}
    	int mid = l + r >> 1;
    	build(o << 1, l, mid);
    	build(o << 1 | 1, mid + 1, r);
    	pull(o);
    };

    std::function<void(int, int, int, int, int)> modify = [&](int o, int l, int r, int ql, int qr) {
    	if (mx[o] == 1) return;
    	if (l == r) {
    		tr[o] = std::sqrt(tr[o]);
    		mx[o] = std::sqrt(mx[o]);
    		return;
    	}
    	int mid = l + r >> 1;
    	if (ql <= mid) modify(o << 1, l, mid, ql, qr);
    	if (qr > mid) modify(o << 1 | 1, mid + 1, r, ql, qr);
    	pull(o);
    };

    std::function<i64(int, int, int, int, int)> query = [&](int o, int l, int r, int ql, int qr) {
    	if (ql <= l and r <= qr) {
    		return tr[o];
    	}
    	int mid = l + r >> 1;
    	i64 res = 0;
    	if (ql <= mid) res += query(o << 1, l, mid, ql, qr);
    	if (qr > mid) res += query(o << 1 | 1, mid + 1, r, ql, qr);
    	return res;
    };

    build(1, 1, n);
    int q;
    std::cin >> q;
    while (q--) {
    	int op, l, r;
    	std::cin >> op >> l >> r;
        if (l > r) std::swap(l, r);
    	if (op) {
    		std::cout << query(1, 1, n, l, r) << "\n";
    	} else {
    		modify(1, 1, n, l, r);
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
