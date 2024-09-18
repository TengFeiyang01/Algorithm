#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
	const int k = 31;
	int i = 0, n = a.size(), j = 0, m = b.size();
	int p = 0, q = std::min(k, n + m);
	std::vector<int> res(q);
	while (i < n and j < m and p < q) {
		if (a[i] <= b[j]) {
			res[p++] = a[i++];
		} else {
			res[p++] = b[j++];
		}
	}
	while (i < n and p < q) res[p++] = a[i++];
	while (j < m and p < q) res[p++] = b[j++];
	return res;
}

struct Seg {
	std::vector<std::vector<int>> tr;
	Seg(int n) {
		tr.resize(n);
	}
	void build(std::vector<int> &a, int o, int l, int r) {
		if (l == r) {
			tr[o] = std::vector<int>{a[l - 1]};
			return;
		}
		int mid = l + r >> 1;
		build(a, o << 1, l, mid);
		build(a, o << 1 | 1, mid + 1, r);
		tr[o] = merge(tr[o << 1], tr[o << 1 | 1]);
	}

	std::vector<int> query(int o, int l, int r, int L, int R) {
		if (L <= l and r <= R) {
			return tr[o];
		}
		int mid = l + r >> 1;
		if (R <= mid) {
			return query(o << 1, l, mid, L, R);
		}
		if (L > mid) {
			return query(o << 1 | 1, mid + 1, r, L, R);
		}
		return merge(query(o << 1, l, mid, L, R), query(o << 1 | 1, mid + 1, r, L, R));
	}
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    Seg t(n * 4);
    t.build(a, 1, 1, n);
    int q;
    std::cin >> q;
    while (q--) {
    	int l, r;
    	std::cin >> l >> r;
    	int ans = 1 << 30;
    	auto b = t.query(1, 1, n, l, r);
    	for (int i = 0; i < b.size(); ++i) {
    		for (int j = i + 1; j < b.size(); ++j) {
    			ans = std::min(ans, b[i] | b[j]);
    		}
    	}
    	std::cout << ans << "\n";
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
