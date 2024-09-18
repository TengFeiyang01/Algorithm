#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, q;
    std::cin >> n >> q;
    std::map<i64, i64> cnt;

    auto f = [&](i64 x) {
    	for (i64 i = 2; i * i <= x; ++i) {
    		while (x % i == 0) {
    			cnt[i]++;
    			x /= i;
    		}
    	}
    	if (x > 1) cnt[x]++;
    };

    auto check = [&]() -> bool {
    	std::map<i64, i64> cntd;
    	for (auto [l, r] : cnt) {
            // 计算的是 d(n)
    		++r;
    		for (i64 i = 2; i * i <= r; ++i) {
    			while (r % i == 0) {
    				cntd[i]++;
    				r /= i;
    			}
    		}
    		if (r > 1) cntd[r]++;
    	}
    	for (auto [l, r] : cntd) {
    		if (cnt[l] < r) return false;
    	}
        // 看 n 是否是 d(n) 的倍数
    	return true;
    };
    f(n);
    while (q--) {
    	i64 k, x;
    	std::cin >> k;
    	if (k == 1) {
    		std::cin >> x;
    		f(x);
    		if (!check()) {
    			std::cout << "NO\n";
    		} else {
    			std::cout << "YES\n";
    		}
    	} else {
    		cnt.clear();
            f(n);
    	}
    }
    std::cout << "\n";
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