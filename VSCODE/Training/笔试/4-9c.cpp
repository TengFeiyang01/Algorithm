#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1000000007;
const int N = 2e3 + 13;

i64 c[N][N];
void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}


void solve() {
    init();
    int n, m, k;
    std::cin >> n >> m >> k;
    i64 res = 0;
    int tot = n + m;
    for (int i = 2; i <= std::min(k - 3, m); ++i) {
        res += c[m][i] % mod * c[n][k - i];
        res %= mod;
    }

    std::cout << res % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
