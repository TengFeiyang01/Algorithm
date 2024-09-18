#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 4>> lines;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
    	int x1, x2, y1, y2;
    	std::cin >> x1 >> y1 >> x2 >> y2;
    	lines.push_back({y1, x2, x1, 1});
    	lines.push_back({y2, x2, x1, -1});
    	a.push_back(x1);
    	a.push_back(x2);
    }
    a.push_back(-100);
    std::ranges::sort(a);
    lines.push_back({0, 0, 0, 0});
    std::ranges::sort(lines);
    auto [l, r] = std::ranges::unique(a);
    a.erase(l, r);
    int m = a.size();
    std::vector<i64> tag(5 << std::__lg(m)), tr(5 << std::__lg(m));
    i64 ans = 0;

    auto pull = [&](int o, int l, int r) {
    	if (tag[o]) tr[o] = a[r] - a[l];  // 完全覆盖
    	else if (l + 1 == r) tr[o] = 0;  // 叶子节点没有宽度  每个叶子代表一条线
    	else tr[o] = tr[o << 1] + tr[o << 1 | 1];
    };

    std::function<void(int, int, int, int, int, int)> update = [&](int o, int l, int r, int ql, int qr, int val) {
    	if (ql <= l and r <= qr) {
    		tag[o] += val;
    		pull(o, l, r);
    		return;
    	}
    	if (l + 1 == r) return;  // 叶子节点
    	int mid = l + r >> 1;
    	if (ql <= mid) update(o << 1, l, mid, ql, qr, val);
    	if (qr > mid) update(o << 1 | 1, mid, r, ql, qr, val);
    	pull(o, l, r);
    };

    for (int i = 1; i < lines.size(); ++i) {
    	ans += tr[1] * (lines[i][0] - lines[i - 1][0]);
    	int l = std::lower_bound(a.begin(), a.end(), lines[i][2]) - a.begin();
    	int r = std::lower_bound(a.begin(), a.end(), lines[i][1]) - a.begin();
    	update(1, 1, m, l, r, lines[i][3]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
