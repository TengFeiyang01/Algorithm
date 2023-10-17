#include <bits/stdc++.h>

void solve() {
    int n, x, m;
    std::cin >> n >> m;
    int lcnt = 0, rcnt = 0;
    std::vector<int> pos;
    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	if (x == -1) lcnt++;
    	else if (x == -2) rcnt++;
    	else pos.emplace_back(x);
    }
    if (lcnt + rcnt == n) {
        std::cout << std::min(m, std::max(lcnt, rcnt)) << "\n";
        return;
    }
    std::sort(pos.begin(), pos.end());
    pos.erase(std::unique(pos.begin(), pos.end()), pos.end());
    int len = pos.size();
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        int x = pos[i];
        ans = std::max(ans, std::min(x, i + 1 + lcnt) + std::min(m - x, len - i - 1 + rcnt));
    }

    std::cout << std::max({ans, std::min(m, len + lcnt), std::min(m, len + rcnt)}) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
