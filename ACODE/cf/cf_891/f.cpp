#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::map<i64, i64> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }

    int q;
    std::cin >> q;
    while (q--) {
    	i64 x, y;
    	std::cin >> x >> y;
    	i64 delta = std::sqrt(1LL * x * x - 4 * y);
    	if (delta * delta != x * x - 4LL * y) {
    		std::cout << "0" << " ";
    		continue;
    	}
    	i64 p = (x + delta) / 2, q = (x - delta) / 2;
    	i64 p1 = x - p, q1 = x - q;
    	if (delta == 0) {  // p == q
            if (p1 == p)
        		std::cout << cnt[p1] * (cnt[p] - 1) / 2 << " ";
            else {
                std::cout << cnt[p1] * cnt[p] << " ";
            }
    	} else {
    		if (p != q1) {
                i64 ans1, ans2;
                if (p1 != p) ans1 = cnt[p] * cnt[p1];
                else ans1 = cnt[p] * (cnt[p] - 1) / 2;
                if (q1 != q) ans2 = cnt[q] * cnt[q1];
                else ans2 = cnt[q] * (cnt[q] - 1) / 2;
                std::cout << ans2 + ans1 << " ";
    		} else {
                if (p1 != p) {
                    std::cout << cnt[p] * cnt[p1];
                } else {
                    std::cout << cnt[p] * (cnt[p] - 1) / 2;
                }
                std::cout << " ";
    		}
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
