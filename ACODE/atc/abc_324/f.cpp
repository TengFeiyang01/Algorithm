#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int N = 100;
int a[N][N], ans[N][N];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= m; ++j) {
            for (int p = 0; p < k; ++p) {
                for (int q = 0; q < k; ++q) {
                    ans[i][j] += a[i + p][j + q];       
                }
            }
        }
    }

    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= m; ++j) {
            std::cout << ans[i][j] << " \n"[j == m - k + 1];
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}