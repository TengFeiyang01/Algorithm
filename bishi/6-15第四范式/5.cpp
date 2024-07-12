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
        return rangeApply(1, 0, n, l, r, v);
	}
};

struct Tag {
	int flap = 0;
    void apply(const Tag &t) {
   		flap ^= t.flap;
    }
};

struct Info {
	int len, s0, s1;
    // 区间操作的话 需要维护len
    void apply(const Tag &t) {
    	if (t.flap) {
	    	std::swap(s0, s1);
    	}
    }
};


Info operator+(const Info &a, const Info &b) {
    Info res;

    res.len = a.len + b.len;

    if (a.len % 2) {
    	res.s0 = a.s0 + b.s1;
    	res.s1 = a.s1 + b.s0;
    } else {
    	res.s0 = a.s0 + b.s0;
    	res.s1 = a.s1 + b.s1;
    }

    return res;
}


void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    LazySegmentTree<Info, Tag> tr(n);
    for (int i = 0; i < n; ++i) {
    	tr.modify(i, Info{1, (s[i] == '1' ? 1 : 0), (s[i] == '1' ? 0 : 1)});

    }
    
    for (int i = 0; i < q; ++i) {
    	int l, r, op;
    	std::cin >> op >> l >> r;
    	--l;
    	if (op == 1) {
    		tr.rangeApply(l, r, Tag{1});
    	} else {
    		auto info = tr.rangeQuery(l, r);
    		std::cout << std::min(info.s1, info.s0) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
