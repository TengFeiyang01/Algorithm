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
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
	int type = -1, flag = 0;
    void apply(const Tag &t) {
    	if (t.type == 0) {
    		flag = 0;
    		type = 0;
    	}

    	if (t.type == 1) {
    		flag = 0;
    		type = 1;
    	}
    	
    	if (t.flag) {
	    	flag ^= t.flag;
    	}
    }
};

struct Info {
    // 区间操作的话 需要维护len
    int len, cnt0, cnt1, sl0, sl1, sr0, sr1, sec0, sec1;
    void apply(const Tag &t) {
    	if (t.type == 0) {
    		cnt0 = sl0 = sr0 = sec0 = len;
    		cnt1 = sl1 = sr1 = sec1 = 0;
    	}
    	if (t.type == 1) {
    		cnt0 = sl0 = sr0 = sec0 = 0;
    		cnt1 = sl1 = sr1 = sec1 = len;
    	}

    	if (t.flag) {
    		std::swap(cnt0, cnt1);
    		std::swap(sl0, sl1);
    		std::swap(sr0, sr1);
    		std::swap(sec0, sec1);
    	}
    }
};


Info operator+(const Info &a, const Info &b) {
    Info res;
	
	res.len = a.len + b.len;

    res.cnt0 = a.cnt0 + b.cnt0;
    res.cnt1 = a.cnt1 + b.cnt1;
    
    res.sl0 = a.cnt1 ? a.sl0 : a.len + b.sl0;
    res.sl1 = a.cnt0 ? a.sl1 : a.len + b.sl1;

    res.sr0 = b.cnt1 ? b.sr0 : b.len + a.sr0;
    res.sr1 = b.cnt0 ? b.sr1 : b.len + a.sr1;

    res.sec0 = std::max({a.sec0, b.sec0, a.sr0 + b.sl0});
    res.sec1 = std::max({a.sec1, b.sec1, a.sr1 + b.sl1});

    return res;
}


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Info> a(n);
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	a[i] = Info{1, !x, x, !x, x, !x, x, !x, x};
    }

    LazySegmentTree<Info, Tag> tr(a);


    for (int i = 0; i < m; ++i) {
    	int l, r, op;
    	std::cin >> op >> l >> r;
	    r++;
    	
    	if (0 <= op and op <= 2) {
    		tr.rangeApply(l, r, Tag{op, op == 2});
    	} else if (op == 3) {
    		std::cout << tr.rangeQuery(l, r).cnt1 << "\n";
    	} else {
    		std::cout << tr.rangeQuery(l, r).sec1 << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

