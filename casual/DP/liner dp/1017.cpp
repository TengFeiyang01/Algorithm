#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, v;
    std::cin >> v >> n;
    std::vector<int> dp(v + 1);
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	for (int j = v; j >= x; --j) {
    		dp[j] = std::max(dp[j], dp[j - x] + x);
    	}
    }
    std::cout << v - dp[v] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
