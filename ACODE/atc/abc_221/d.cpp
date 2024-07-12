#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	a.push_back({x, 1});
    	a.push_back({x + y, -1});
    }
    std::ranges::sort(a);
    std::vector<int> ans(n + 1);
    int now = 0, pre = 0;
    // 第一次遇到端点更新答案 其他时间不管
    for (int i = 0; auto [l, r] : a) {
    	if (i and a[i][0] != a[i - 1][0]) {
    		ans[now] += a[i][0] - a[i - 1][0];
    	}
    	now += a[i++][1];
    } 
    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
