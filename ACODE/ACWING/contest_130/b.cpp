#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        s[i] += s[i - 1];
    }
    int x = -1, y = -1, z = -1;
    i64 ans = -1e14;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        for (int t = 0; t < i; ++t) {
            if (s[t] > s[j]) {
                j = t;
            }
        }
        int k = i;
        for (int t = i + 1; t <= n; ++t) {
            if (s[t] > s[k]) {
                k = t;
            }
        }
        // 容斥[0, i] + [j, k] 两段等于[0, k] - [0, i] + [0, j]
        i64 now = s[j] - s[i] + s[k];
        if (now > ans) {
            ans = now;
            x = j, y = i, z = k;
        }
    }
    std::cout << x << " " << y << " " << z << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
