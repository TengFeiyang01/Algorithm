#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 A, M, L, R;
    std::cin >> A >> M >> L >> R;
    i64 ans = 0;
    i64 left = 0, right = 0;

    if (A <= L) {
        i64 now = A + (L - A + M - 1) / M * M;
        ans = (R - now + 1 + M - 1) / M;
    } else if (A >= R) {
        i64 now = A - (A - R + M - 1) / M * M;
        ans = (now - L + 1 + M - 1) / M;
    } else {
        i64 left = (A - L + 1 + M - 1) / M;
        i64 right = (R - A + 1 + M - 1) / M;
        ans = left + right - 1;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}