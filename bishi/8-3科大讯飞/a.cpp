#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
    }

    int ans = n;
    std::vector<int> st(n);

    for (int i = 0; i < n; ++i) {
        if (!st[i]) {
            int j = i;
            while (!st[j]) {
                st[j] = 1;
                j = a[j];
            }
            ans--;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
