#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, s;
    std::cin >> n >> k >> s;
    i64 l = 0, r = 1e12;

    auto check = [&](i64 x) {
    	i64 p = (sqrtl(1 + 8LL * x) - 1) / 2;
    	x -= p * (p + 1) / 2;
    	i64 cur = 0;
    	i64 cnt = p + 1 - x; // 这是n-p的个数

    	if (k <= cnt) {
    		return k * (n - p) <= s;
    	} else {
    		cur += cnt * (n - p);
    		i64 cnt1 = x + 1; // n-p-1的个数
    		if (cnt + cnt1 >= k) {
    			return cur + (k - cnt) * (n - p - 1) <= s;
    		} else {
    			cur += cnt1 * (n - p - 1);
    			i64 t = k - cnt - cnt1, r = n - p - 2;
    			return cur + (r + r - t + 1) * t / 2 <= s;
    		}
    	}
    };	
    while (l < r) {
    	i64 mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << l << "\n";
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
