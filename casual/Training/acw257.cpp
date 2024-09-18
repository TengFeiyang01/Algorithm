#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct PresistentSegmentTree {
	struct Info {
		int l, r, cnt;
	};
	std::vector<Info> tr;
	std::vector<int> root;
	int idx = 0;

	PresistentSegmentTree(int n) : tr(n << 5), root(n) {
		std::function<void(int &, int, int)> build = [&](int &u, int l, int r) {
			u = ++idx;
			if (l == r) return;
			int mid = l + r >> 1;
			build(tr[u].l, l, mid);
			build(tr[u].r, mid + 1, r);
		};
		build(root[0], 1, n);
	}

	void modify(int pre, int &now, int l, int r, int c) {
		now = ++idx;
		tr[now] = tr[pre];
		tr[now].cnt++;
		if (l == r) return;
		int mid = l + r >> 1;
		if (c <= mid) {
			modify(tr[pre].l, tr[now].l, l, mid, c);
		} else {
			modify(tr[pre].r, tr[now].r, mid + 1, r, c);
		}
	}

	int query(int pre, int now, int l, int r, int k) {
		if (l == r) return l;
		int mid = l + r >> 1, sum = tr[tr[now].l].cnt - tr[tr[pre].l].cnt;
		if (k <= sum) {
			return query(tr[pre].l, tr[now].l, l, mid, k);
		} else {
			return query(tr[pre].r, tr[now].r, mid + 1, r, k - sum);
		}
	}
};


void solve() {
    int n, k, q, l, r;
    std::cin >> n >> q;
    std::vector<int> a(n + 1), nums;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	nums.push_back(a[i]);
    }
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    auto find = [&](int x) {
    	return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };

    PresistentSegmentTree tr(n + 1);
    for (int i = 1; i <= n; ++i) {
    	a[i] = find(a[i]);
    	tr.modify(tr.root[i - 1], tr.root[i], 1, n, a[i]);
    }
    while (q--) {
    	std::cin >> l >> r >> k;
    	std::cout << nums[tr.query(tr.root[l - 1], tr.root[r], 1, n, k) - 1] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
