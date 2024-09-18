#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    struct info {
        i64 sum[2];
    };

    std::vector<info> tr(n << 3);

    auto poll = [&](int o, int k) {
        tr[o].sum[k] = tr[o << 1].sum[k] + tr[o << 1 | 1].sum[k];
    };

    std::function<void(int, int, int, int, int)> modify = [&](int o, int l, int r, int pos, int k) {
        if (l == r) {
            tr[o].sum[k]++;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) modify(o << 1, l, mid, pos, k);
        else if (pos > mid) modify(o << 1 | 1, mid + 1, r, pos, k);
        poll(o, k);
    };

    std::function<i64(int, int, int, int, int, int)> query = [&](int o, int l, int r, int ql, int qr, int k) {
        if (ql <= l and r <= qr) {
            return tr[o].sum[k];
        }
        int mid = l + r >> 1;
        i64 ans = 0;
        if (ql <= mid) ans += query(o << 1, l, mid, ql, qr, k);
        if (qr > mid) ans += query(o << 1 | 1, mid + 1, r, ql, qr, k);
        return ans;
    };
    
    for (int i = 0; i < m; ++i) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 1) {
            modify(1, 1, n, l, 0);
            modify(1, 1, n, r, 1);
        } else {
            int x;
            std::cout << query(1, 1, n, 1, r, 0) - query(1, 1, n, 1, l - 1, 1) << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
