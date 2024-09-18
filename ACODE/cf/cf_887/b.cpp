#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;

i64 f[N + 1];

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    int ans = 0;
    if (k >= 29) {
        std::cout << "0\n";
        return;
    }

    int t = -1;
    i64 p = f[k - 1], q = f[k - 2];

    for (int x = 0; x <= n; x++) {
        if ((n - q * x) % p == 0 and (n - q * x) / p >= x) {
            t = x;
            break;
        }
    }
    
    if (t == -1) {
        std::cout << "0\n";
        return;
    }

    for (i64 x = t; x <= n; x += p) {
        if ((n - q * x) / p >= x) {
            ans++;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 40; ++i) f[i] = f[i - 1] + f[i - 2];

    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
