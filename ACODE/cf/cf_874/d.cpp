#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<int> id(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        id[a[i]] = i;
    }

    if (n == 1) {
        std::cout << 1 << "\n";
        return;
    }

    int x = id[n];
    if (a[0] == n) x = id[n - 1];

    if (x == n - 1) {
        x = n;
    }

    int y = x - 2;

    while (y > 0 and a[y] > a[0]) {
        y--;
    }
    for (int i = x; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    for (int i = x - 1; i > y; --i) {
        std::cout << a[i] << " ";
    }
    for (int i = 0; i <= y; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}