#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 2e5 + 10;

struct Segment {
	double x, y1, y2;
	int v;
	bool operator<(const Segment &seg) const {
		return x < seg.x;
	}
}seg[N * 2];

struct Node {
	int l, r, cnt;
	double len;
} tr[N << 3];
std::vector<double> ys;

int find(double y) {
	return std::lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int o) {
	if (tr[o].cnt) {
		tr[o].len = ys[tr[o].r + 1] - ys[tr[o].l];
	} else if (tr[o].l != tr[o].r) {
		tr[o].len = tr[o << 1].len + tr[o << 1 | 1].len;
	} else {
		tr[o].len = 0;
	}
}

void build(int o, int l, int r) {
	tr[o] = {l, r, 0, 0};
	if (l == r) {
		return;
	}
	int mid = l + r >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
}

void modify(int o, int l, int r, int v) {
	if (l <= tr[o].l && tr[o].r <= r) {
		tr[o].cnt += v;
	} else {
		int mid = tr[o].l + tr[o].r >> 1;
		if (l <= mid) {
			modify(o << 1, l, r, v);
		}
		if (r > mid) {
			modify(o << 1 | 1, l, r, v);
		}
	}
	pushup(o);
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0, j = 0; i < n; ++i) {
    	double x1, x2, y1, y2;
    	std::cin >> x1 >> x2 >> y1 >> y2;
    	seg[j++] = {x1, y1, y2, 1};
    	seg[j++] = {x2, y1, y2, -1};
    	ys.push_back(y1);
    	ys.push_back(y2);
    }
    n <<= 1;
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    std::sort(seg, seg + n);
    build(1, 0, ys.size() - 2);
    
    double ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (i) {
    		ans += tr[1].len * (seg[i].x - seg[i - 1].x);
    	}
    	modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].v);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}