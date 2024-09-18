#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int D = 22;
const int N = (1 << D) - 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> dp(N + 1), a(n + 1);
    a[0] = -1;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        dp[N & ~a[i]] = i;
    }

    for (int i = 0; i < D; ++i) {
        for (int mask = 0; mask <= N; ++mask) {
            if (mask & 1 << i and dp[mask] != 0) {
                dp[mask ^ 1 << i] = dp[mask];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << a[dp[a[i]]] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
