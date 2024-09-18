#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 2e5 + 13;

struct node1 {
	int l, r, t, id;
}qs[N];

struct node2 {
	int l, r;
}cs[N];

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    int B = pow(n, 0.666);
    int cntc = 0, cntq = 0;
    for (int i = 0; i < m; ++i) {
    	char op;
    	int l, r;
    	std::cin >> op >> l >> r;
    	if (op == 'Q') {
            qs[++cntq] = {l, r, cntc, cntq};
    	} else {
            cs[++cntc] = {l, r};
    	}
    }
    int l = 1, r = 0, t = 0, now = 0;

    std::sort(qs + 1, qs + cntq + 1, [&](auto &x, auto &y){
    	return x.l / B == y.l / B ? (x.r / B == y.r / B ? x.t < y.t : x.r < y.r) : x.l < y.l;
    });

    std::vector<int> cnt(1000001);
    std::vector<int> ans(cntq);
    auto add = [&](int x) {
        now += !cnt[x]++;
    };

    auto del = [&](int x) {
        now -= !--cnt[x];
    };
    auto update = [&](int x, int t) {
        if (qs[x].l <= cs[t].l and cs[t].l <= qs[x].r) {
            del(a[cs[t].l]);
            add(cs[t].r);
        }
        std::swap(a[cs[t].l], cs[t].r);
    };

    for (int i = 1; i <= cntq; ++i) {
        auto [ql, qr, qt, id] = qs[i];
        while (l > ql) add(a[--l]);
        while (l < ql) del(a[l++]);
        while (r > qr) del(a[r--]);
        while (r < qr) add(a[++r]);
        while (t < qt) update(i, ++t);
        while (t > qt) update(i, t--);
    	ans[id - 1] = now;
    }
    for (auto x : ans) {
    	std::cout << x << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
