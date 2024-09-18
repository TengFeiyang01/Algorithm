#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1e5 + 13;


int n, m, x;
i64 tr[22][N << 2], tag[N << 2];

void push_up(int k) {
	for (int i = 0; i < 22; ++i) {
		tr[i][k] = tr[i][k << 1] + tr[i][k << 1 | 1];
	}
}

void push_down(int k, int son) {
	if (tag[k]) {
		tag[k << 1] ^= tag[k];
		tag[k << 1 | 1] ^= tag[k];
		for (int i = 0; i < 22; ++i) {
			if (tag[k] >> i & 1) {
				tr[i][k << 1] = son - (son >> 1) - tr[i][k << 1];
				tr[i][k << 1 | 1] = (son >> 1) - tr[i][k << 1 | 1];
			}
		}
		tag[k] = 0;
	}
}

void build(int l, int r, int k) {
	if (l == r) {
		std::cin >> x;
		for (int i = 0; i < 22; ++i) {
			if (x >> i & 1) {
				tr[i][k] = 1;
			}
		}
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, k << 1);
	build(mid + 1, r, k << 1 | 1);
	push_up(k);
}

void updade(int L, int R, int x, int l, int r, int k) {
	if (L <= l and r <= R) {
		tag[k] ^= x;
		for (int i = 0; i < 22; ++i) {
			if (x >> i & 1) {
				tr[i][k] = r - l + 1 - tr[i][k];
			}
		}
		return;
	}
	int mid = l + r >> 1;
	push_down(k, r - l + 1);
	if (L <= mid) updade(L, R, x, l, mid, k << 1);
	if (R > mid) updade(L, R, x, mid + 1, r, k << 1 | 1);
	push_up(k);
}

i64 query(int L, int R, int l, int r, int k) {
	if (L <= l and r <= R) {
		i64 cnt = 0;
		for (int i = 0; i < 22; ++i) {
			cnt += tr[i][k] << i;
		}
		return cnt;
	}
	int mid = l + r >> 1;
	push_down(k, r - l + 1);
	i64 ans = 0;
	if (L <= mid) ans += query(L, R, l, mid, k << 1);
	if (R > mid) ans += query(L, R, mid + 1, r,  k << 1 | 1);
	return ans;
}

void solve() {
    std::cin >> n;	
    build(1, n, 1);
    std::cin >> m;
    while (m--) {
    	int op, l, r;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> l >> r;
    		std::cout << query(l, r, 1, n, 1) << "\n";
    	} else {
    		std::cin >> l >> r >> x;
    		updade(l, r, x, 1, n, 1);
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
