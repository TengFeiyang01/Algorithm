#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(n + 1);
    std::vector<i64> res(n + 1);
    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
    	cnt[x]++;
    }

    std::vector<bool> hasD(n + 1, false);

    for (int i = n; i > 0; --i) {
    	i64 c = 0;
    	for (int j = i; j <= n; j += i) {
    		if (cnt[i]) {
    			hasD[j] = true;
    		}
    		c += cnt[j];
    		res[i] -= res[j];
    	}
    	res[i] += c * (c - 1) / 2;
    }

    i64 ans = 0;
    for (int i = 0; i <= n; ++i) {
    	if (!hasD[i]) {
    		ans += res[i];
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
