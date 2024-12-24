#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> f(n + 1), st(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i * 2; j < n; j += i) {
            f[j] += i;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!st[i]) {
            // i -> f[i] j == f[i]
            // j -> f[j]  i==f[j] 
            if (i == f[f[i]]) {
                st[i] = st[f[i]] = 1;
                std::cout << i << " " << f[i] << "\n";
            }
        }
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}