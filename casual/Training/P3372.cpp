#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 1e5 + 13;

i64 w[N];

struct Node {
    int l, r;
    i64 val, add;
}tr[N * 4];

void pushup(int o) {
    tr[o].val = tr[o << 1].val + tr[o << 1 | 1].val;
}

void pushdown(int o) {
    auto &root = tr[o], &left = tr[o << 1], &right = tr[o << 1 | 1];
    if (root.add) {
        left.add += root.add;
        left.val += (i64)(left.r - left.l + 1) * root.add;
        right.add += root.add;
        right.val += (i64)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int o, int l, int r) {
    if (l == r) tr[o] = {l, r, w[l], 0};
    else {
        tr[o] = {l , r};
        int mid = l + r >> 1;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        pushup(o);
    }
}

void modify(int o, int L, int R, int d) {
    if (tr[o].l >= L && tr[o].r <= R) {
        tr[o].val += (i64)(tr[o].r - tr[o].l + 1) * d;
        tr[o].add += d;
    } else {
        pushdown(o);
        int mid = tr[o].l + tr[o].r >> 1;
        if (L <= mid) modify(o << 1, L, R, d);
        if (R > mid) modify(o << 1 | 1, L, R, d);
        pushup(o);
    }
}

i64 query(int o, int L, int R) {
    if (tr[o].l >= L && tr[o].r <= R) {
        return tr[o].val;
    }
    pushdown(o);
    int mid = tr[o].l + tr[o].r >> 1;
    i64 ans = 0;
    if (L <= mid) ans = query(o << 1, L, R);
    if (R > mid) ans += query(o << 1 | 1, L, R);
    return ans;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> w[i];
    build(1, 1, n);
    while (q--) {
        int l, r, op;
        std::cin >> op >> l >> r;
        if (op == 2) {
            std::cout << query(1, l, r) << "\n";
        } else {
            int d;
            std::cin >> d;
            modify(1, l, r, d);
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();
    return 0;
}
