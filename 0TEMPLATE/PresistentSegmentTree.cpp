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
