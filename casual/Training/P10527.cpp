#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::random_shuffle(a.begin(), a.end());
    std::bitset<1<<20> dp;
    dp.set(0);
    for (auto x : a) {
    	auto ndp = (dp << x) | (dp >> x);
    	for (int j = x; j; --j) {
    		ndp[x - j] = ndp[x - j] | dp[j];
    	}
    	dp = ndp;
    }
    std::cout << dp._Find_first() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
