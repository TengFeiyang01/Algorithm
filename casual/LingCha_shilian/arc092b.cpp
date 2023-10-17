#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    int ans = 0;
    for (int k = 0; k < 29; ++k) {
    	int mask = (1 << k + 1) - 1;
        std::sort(a.begin(), a.end(), [&](int x, int y) {return (x & mask) < (y & mask); });
        std::sort(b.begin(), b.end(), [&](int x, int y) {return (x & mask) < (y & mask); });

        int cnt = 0;
        int i = n - 1, j = n - 1, p = n - 1, q = n - 1;
        int l1 = 1 << k, r1 = (1 << k + 1) - 1, l2 = 3 << k, r2 = (1 << k + 2) - 1;
        for (int s : a) {
            while (i >= 0 && (s & mask) + (b[i] & mask) >= l1) { i--; }
            while (j >= 0 && (s & mask) + (b[j] & mask) > r1) { j--; }
            while (p >= 0 && (s & mask) + (b[p] & mask) >= l2) { p--; }
            while (q >= 0 && (s & mask) + (b[q] & mask) > r2) { q--; }
            cnt += j - i + q - p;
        }
        ans |= (cnt & 1) << k;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}