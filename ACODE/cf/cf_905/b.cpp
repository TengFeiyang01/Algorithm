#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int ans = k;
    int cnt2 = 0, cnt4 = 0, mod3 = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        if (a[i] % 2 == 0) cnt2++;
        if (a[i] % 4 == 0) cnt4++;
        if (a[i] % 4 == 3) {
            mod3++;
        }
    	ans = std::min(ans, (k - a[i] % k) % k);
    }
    if (k == 4) {
        if (cnt4 or cnt2 >= 2) {
            std::cout << "0\n";
        } else {
            if (cnt2 == 1 || mod3) {
                std::cout << 1 << "\n";
            } else {
                std::cout << 2 << "\n";
            }
        }
        return;
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