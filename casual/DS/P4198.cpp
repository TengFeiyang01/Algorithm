#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> sum(4 << std::__lg(n));
    std::vector<double> mx(4 << std::__lg(n));
  
    std::function<int(int, int, int, double)> dfs = [&](int o, int l, int r, double mls) {
        if (mx[o] <= mls) return 0;
        if (l == r) return int(mx[o] > mls);
        int mid = l + r >> 1;
        if (mx[o << 1] <= mls) return dfs(o << 1 | 1, mid + 1, r, mls);
        else return dfs(o << 1, l, mid, mls) + sum[o] - sum[o << 1];
    };
    
    auto pull = [&](int o, int l, int r) {
    	mx[o] = std::max(mx[o << 1], mx[o << 1 | 1]);
        int mid = l + r >> 1;
        sum[o] = sum[o << 1] + dfs(o << 1 | 1, mid + 1, r, mx[o << 1]);
    };

    std::function<void(int, int, int, int, double)> modify = [&](int o, int l, int r, int pos, double val) {
    	if (l == r) {
    		sum[o] = 1;
    		mx[o] = val;
    		return;
    	}
    	int mid = l + r >> 1;
    	if (pos <= mid) modify(o << 1, l, mid, pos, val);
    	else modify(o << 1 | 1, mid + 1, r, pos, val);
    	pull(o, l, r);
    };


    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	modify(1, 1, n, x, double(y) / x);
    	std::cout << sum[1] << "\n"; 
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
