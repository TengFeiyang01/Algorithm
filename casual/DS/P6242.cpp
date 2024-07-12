#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 5e5 + 13;

i64 sum[N << 2], mxa[N << 2], se[N << 2], cnt[N << 2], add[N << 2], add2[N << 2], add3[N << 2], add4[N << 2], mxb[N << 2];
int a[N];

void pull(int o) {
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
	mxa[o] = std::max(mxa[o << 1], mxa[o << 1 | 1]);
	mxb[o] = std::max(mxb[o << 1], mxb[o << 1 | 1]);
	if (mxa[o << 1 | 1] == mxa[o << 1]) {
		se[o] = std::max(se[o << 1], se[o << 1 | 1]);
		cnt[o] = cnt[o << 1] + cnt[o << 1 | 1];
	} else {
		se[o] = std::max({se[o << 1], se[o << 1 | 1], std::min(mxa[o << 1], mxa[o << 1 | 1])});
		cnt[o] = mxa[o << 1] > mxa[o << 1 | 1] ? cnt[o << 1] : cnt[o << 1 | 1];
	}
}

void push(int o) {

}

void build(int o, int l, int r) {
	if (l == r) {
		sum[o] = mxa[o] = mxb[o] = a[l];
		cnt[o] = 1;
		se[o] = -inf;
		add[o] = 0;
		return;
	}
	int m = l + r >> 1;
	build(o << 1, l, m);
	build(o << 1 | 1, m + 1, r);
	pull(o);
}


i64 query_sum(int o, int l, int r, int ql, int qr) {
	if (ql <= l and r <= qr) {
		return sum[o];
	}
	push(o);
	i64 ans = 0, m = l + r >> 1;
	if (ql <= m) ans += query_sum(o << 1, l, m, ql, qr);
	if (qr > m) ans += query_sum(o << 1 | 1, m + 1, r, ql, qr);
	return ans;
}

i64 query_maxa(int o, int l, int r, int ql, int qr) {
	if (ql <= l and r <= qr) {
		return mxa[o];
	}
	push(o);
	i64 ans = -inf, m = l + r >> 1;
	if (ql <= m) ans = std::max(ans, query_maxa(o << 1, l, m, ql, qr));
	if (qr > m) ans = std::max(ans, query_maxa(o << 1 | 1, m + 1, r, ql, qr));
	return ans;
}

i64 query_maxb(int o, int l, int r, int ql, int qr) {
	if (ql <= l and r <= qr) {
		return mxb[o];
	}
	push(o);
	i64 ans = -inf, m = l + r >> 1;
	if (ql <= m) ans = std::max(ans, query_maxb(o << 1, l, m, ql, qr));
	if (qr > m) ans = std::max(ans, query_maxb(o << 1 | 1, m + 1, r, ql, qr));
	return ans;
}

void rangeAdd(int o, int l, int r, int ql, int qr, i64 val) {
	if (ql <= l and r <= qr) {
		sum[o] += val * cnt[o] + val * (r - l + 1 - cnt[o]);
		mxa[o] += val;
		mxb[o] = std::max(mxb[o], mxa[o]);
		if (se[o] != -inf) se[o] += val;
		add[o] += val;
	}
}

void solve() {
    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
