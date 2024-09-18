#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    struct info {
        i64 sum, tag, len;
    };

    std::vector<info> tr(n << 3);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = n - 1; i >= 1; --i) {
    	a[i] -= a[i - 1];
    }

    auto poll = [&](int o) {
        tr[o].sum = tr[o << 1].sum + tr[o << 1 | 1].sum;
        tr[o].len = tr[o << 1].len + tr[o << 1 | 1].len;
    };

    auto push = [&](int o) {
        if (tr[o].tag) {
            tr[o << 1].sum += tr[o].tag * tr[o << 1].len;
            tr[o << 1 | 1].sum += tr[o].tag * tr[o << 1 | 1].len;
            tr[o << 1].tag += tr[o].tag;
            tr[o << 1 | 1].tag += tr[o].tag;
            tr[o].tag = 0;
        }
    };

    std::function<void(int, int, int)> build = [&](int o, int l, int r) {
        if (l == r) {
            tr[o] = {a[l - 1], 0, r - l + 1};
            return;
        }
        int mid = l + r >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        poll(o);
    };

    std::function<void(int, int, int, int, int, i64)> modify = [&](int o, int l, int r, int ql, int qr, i64 val) {
        if (ql <= l and r <= qr) {
            tr[o].sum += val * tr[o].len;
            tr[o].tag += val;
            return;
        }
        push(o);
        int mid = l + r >> 1;
        if (ql <= mid) modify(o << 1, l, mid, ql, qr, val);
        if (qr > mid) modify(o << 1 | 1, mid + 1, r, ql, qr, val);
        poll(o);
    };

    std::function<i64(int, int, int, int, int)> query = [&](int o, int l, int r, int ql, int qr) {
        if (ql <= l and r <= qr) {
            return tr[o].sum;
        }
        push(o);
        int mid = l + r >> 1;
        i64 ans = 0;
        if (ql <= mid) ans += query(o << 1, l, mid, ql, qr);
        if (qr > mid) ans += query(o << 1 | 1, mid + 1, r, ql, qr);
        return ans;
    };
    
    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int op, l, r;
        std::cin >> op;
        if (op == 1) {
            i64 k, d;
            std::cin >> l >> r >> k >> d;
            modify(1, 1, n, l, l, k);
            if (l + 1 <= r) modify(1, 1, n, l + 1, r, d);
            if (r < n) modify(1, 1, n, r + 1, r + 1, -(k + d * (r - l)));
        } else {
            int x;
            std::cin >> x;
            std::cout << query(1, 1, n, 1, x) << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
