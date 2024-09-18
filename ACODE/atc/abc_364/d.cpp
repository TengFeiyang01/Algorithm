#include <bits/stdc++.h>
using i64 = long long;


void solve() { 
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::ranges::sort(a);
    while (q--) {
        int x, k;
        std::cin >> x >> k;
        if (x <= a[0]) {
            std::cout << a[k - 1] - x << "\n";
        } else if (x >= a[n - 1]) {
            std::cout << x - a[n - k] << "\n";
        } else {
            int l = 0, r = int(1e9);
            while (l < r) {
                int mid = l + r >> 1;
                if ((std::ranges::upper_bound(a, x + mid) - a.begin()) - (std::ranges::lower_bound(a, x - mid) - a.begin()) >= k) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            std::cout << r << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();

    return 0;
}