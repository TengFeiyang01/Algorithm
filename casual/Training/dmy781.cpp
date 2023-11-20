#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 思路 扫描线 对于所有询问从大到小处理 一次加入大于当前询问的数的a[i] 那么当前位置的答案就转换为区间的最小值
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> tr(n << 3, inf);
    std::vector<std::array<int, 2>> a(n);
    std::vector<std::array<int, 4>> queries(q);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    	a[i][1] = i + 1;
    }
    
    for (int i = 0; i < q; ++i) {
    	int l, r, x;
    	std::cin >> l >> r >> x;
    	queries[i] = {x, l, r, i};
    }
    std::sort(a.begin(), a.end());
    std::sort(queries.begin(), queries.end());
    std::reverse(a.begin(), a.end());
    std::reverse(queries.begin(), queries.end());

    std::function<void(int, int, int, int, int)> update = [&](int o, int pos, int val, int l, int r) {
    	if (l == r) {
    		tr[o] = val;
            return;
    	}
    	int mid = l + r >> 1;
    	if (pos <= mid) update(o << 1, pos, val, l, mid);
    	else update(o << 1 | 1, pos, val, mid + 1, r);
    	tr[o] = std::min(tr[o << 1 | 1], tr[o << 1]);
    };

    std::function<int(int, int, int, int, int)> query = [&](int o, int l, int r, int L, int R) {
    	if (L <= l and r <= R) {
    		return tr[o];
    	}
    	int mid = l + r >> 1, ans = inf;
    	if (L <= mid) {
    		ans = query(o << 1, l, mid, L, R);
    	} 
    	if (R > mid) ans = std::min(ans, query(o << 1 | 1, mid + 1, r, L, R));
    	return ans;
    };
    std::vector<int> ans(q);
    int i = 0;
    for (const auto &qs : queries) {
    	int x = qs[0], l = qs[1], r = qs[2], id = qs[3];
        // std::cout << x << " " << l << " " << r << "\n";
    	while (i < n and a[i][0] >= x) {
    		update(1, a[i][1], a[i][0], 1, n);
    		i++;
    	}
    	int val = query(1, 1, n, l, r);
    	ans[id] = val == inf ? -1 : val;
    }
    for (int i = 0; i < q; ++i) {
    	std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
