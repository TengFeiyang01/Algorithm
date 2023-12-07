#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    LazySegmentTree() : n(0) {}

    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }

    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            // 左闭右开
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        rangeApply(1, 0, n, l, r, v);
    }
};

int mod;

struct Tag {
    i64 add = 0, mul = 1;
    i64 P = mod;
    void apply(const Tag &t) {
        mul = mul * t.mul;
        add = add * t.mul + t.add;
        mul %= P;
        add %= P;
    }
};

struct Info {
    i64 val = 0;
    i64 len = 1, P = mod;
    void apply(const Tag &t) {
        val = val * t.mul % P + t.add * len % P;
        val %= P;
    }
};


Info operator+(const Info &a, const Info &b) {
    Info res;
    res.val = (a.val + b.val) % mod;
    res.len = a.len + b.len;
    return res;
}

void solve() {
    int n;
    std::cin >> n >> mod;
    std::vector<Info> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].val;
    }
    LazySegmentTree<Info, Tag> Seg(a);
    int m;
    std::cin >> m;
    while (m--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        --l;
        if (op == 3) {
            std::cout << Seg.rangeQuery(l, r).val % mod << "\n";
        } else {
            i64 x;
            std::cin >> x;
            if (op == 1) {
                Seg.rangeApply(l, r, {0, x});
            } else {
                Seg.rangeApply(l, r, {x, 1});
            }
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
