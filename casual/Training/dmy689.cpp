#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

class Segtree {
public:
	int n;
	std::vector<int> tr;
	Segtree(int n = 0) {
		init(n);
	}

	void init(int n) {
		this->n = n;
		tr.resize(n << 2);
		tr.assign(n << 2, -1);
	}

	void update(int val, int pos, int l, int r, int o = 1) {
		if (l == r) {
			tr[o] = pos;
			return;
		}
		int mid = l + r >> 1;
		if (val <= mid) {
			update(val, pos, l, mid, o << 1);
		} else {
			update(val, pos, mid + 1, r, o << 1 | 1);
		}
		tr[o] = std::min(tr[o << 1], tr[o << 1 | 1]);
	}

	int query(int pos, int l, int r, int o = 1) {
		if (l == r) {
			return l;
		}
		int mid = l + r >> 1;
		// 如果 [l, mid] 中的数字中下标最小的那个在当前区间的左侧 那么答案至多是mid
		if (tr[o << 1] < pos) {
			return query(pos, l, mid, o << 1);
		} else {
			return query(pos, mid + 1, r, o << 1 | 1);
		}
	}
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	a[i]++;
    }

    std::vector<std::array<int, 3>> queries(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> queries[i][1] >> queries[i][0];
    	queries[i][2] = i;
    }
    std::sort(queries.begin(), queries.end());
    std::vector<int> ans(m);
    Segtree t(n);
    
    for (int i = 0, j = 0; i < n; ++i) {
    	if (a[i] <= n) {
    		t.update(a[i], i + 1, 1, n + 1);
    	}
    	while (j < m and queries[j][0] == i + 1) {
    		ans[queries[j][2]] = t.query(queries[j][1], 1, n + 1) - 1;
    		j++;
    	}
    }
    for (int i = 0; i < m; ++i) {
    	std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
