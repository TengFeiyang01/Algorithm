#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 2e5 + 13;

int n, q;
std::string s;
struct info {
    std::string l, r;
    bool ok;
    int sz;
    i64 t;
} seg[N << 2];

info operator + (info A, info B) {
    info ans;
    ans.sz = A.sz + B.sz;
    ans.ok = true;
    if (!A.ok || !B.ok) {
        ans.ok = false;
    }
    ans.t = 0;
    if (A.sz == 1 && B.sz == 1) {
        ans.l = ans.r = A.l + B.l;
        if (ans.l[0] == ans.l[1]) {
            ans.ok = false;
        }
    } else if (A.sz == 1) {
        ans.l = A.l;
        ans.l += B.l[0];
        ans.r = B.r;
        if (ans.l[0] == ans.l[1] || ans.l[0] == B.l[1]) {
            ans.ok = false;
        }
    } else if (B.sz == 1) {
        ans.l = A.l;
        ans.r = B.r;
        ans.r = A.r[1] + ans.r;
        if (ans.r[0] == ans.r[1] || ans.r[1] == A.r[0]) {
            ans.ok = false;
        }
    } else {
        ans.l = A.l, ans.r = B.r;
        if (A.r[1] == B.l[0] || A.r[0] == B.l[0] || A.r[1] == B.l[1]) {
            ans.ok = false;
        }
    }
    return ans;
}

void pushup(int o) {
    seg[o] = seg[o << 1] + seg[o << 1 | 1];
}

void setTag(int o, i64 t) {
    seg[o].t += t;
    auto update = [&](char c) {
        i64 cur = c - 'a';
        cur += t;
        cur %= 26;
        return (char)(cur + 'a');
    };
    seg[o].l[0] = update(seg[o].l[0]);
    seg[o].l[1] = update(seg[o].l[1]);
    seg[o].r[0] = update(seg[o].r[0]);
    seg[o].r[1] = update(seg[o].r[1]);
}

void pushdown(int o) {
    if (seg[o].t > 0) {
        setTag(o << 1, seg[o].t);
        setTag(o << 1 | 1, seg[o].t);
        seg[o].t = 0;
    }
}

void build(int l = 1, int r = n, int o = 1) {
    seg[o].t = 0;
    seg[o].ok = true;
    if (l == r) {
        seg[o].l = "";
        seg[o].r = "";
        seg[o].l += s[l];
        seg[o].r += s[l];
        seg[o].sz = 1;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, o << 1);
    build(mid + 1, r, o << 1 | 1);
    pushup(o);
}

void modify(int L, int R, i64 t, int l = 1, int r = n, int o = 1) {
    if (L <= l and r <= R) {
        setTag(o, t);
        return;
    }
    pushdown(o);
    int mid = l + r >> 1;
    if (R <= mid) {
        modify(L, R, t, l, mid, o << 1);
    } else if (L > mid) {
        modify(L, R, t, mid + 1, r, o << 1 | 1);
    } else {
        modify(L, mid, t, l, mid, o << 1);
        modify(mid + 1, R, t, mid + 1, r, o << 1 | 1);
    }
    pushup(o);
}

info query(int L, int R, int l = 1, int r = n, int o = 1) {
    if (L <= l and r <= R) {
        return seg[o];
    }
    pushdown(o);
    int mid = l + r >> 1;
    if (R <= mid) {
        return query(L, R, l, mid, o << 1);
    } else if (L > mid) {
        return query(L, R, mid + 1, r, o << 1 | 1);
    } else {
        return query(L, mid, l, mid, o << 1) + query(mid + 1, R, mid + 1, r, o << 1 | 1);
    }
}


void solve() {
    std::cin >> n >> q >> s;
    s = "*" + s;
    build();
    for (int i = 0; i < q; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, t;
            std::cin >> l >> r >> t;
            modify(l, r, t);
        } else {
            int l, r;
            std::cin >> l >> r;
            auto ans = query(l, r);
            if (ans.ok) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }
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