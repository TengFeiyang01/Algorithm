#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> pre_l(n + 2), pre_r(n + 2, inf), suf_l(n + 2), suf_r(n + 2, inf);
    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> l[i] >> r[i];
    	pre_l[i] = std::max(pre_l[i - 1], l[i]);
    	pre_r[i] = std::min(pre_r[i - 1], r[i]);
    }
    for (int i = n; i >= 1; --i) {
    	suf_l[i] = std::max(suf_l[i + 1], l[i]);
    	suf_r[i] = std::min(suf_r[i + 1], r[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	ans = std::max({0, ans, std::min(pre_r[i - 1], suf_r[i + 1]) - std::max(pre_l[i - 1], suf_l[i + 1])});
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}