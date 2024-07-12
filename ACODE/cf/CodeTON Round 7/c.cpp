#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> b(n);
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
        a[i][1] = i;
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    std::ranges::sort(a);
    std::ranges::sort(b);

    for (int i = n - x, j = 0; i < n; ++i, ++j) {
        a[i][2] = b[j];
    }
    for (int i = 0; i < n - x; ++i) {
        a[i][2] = b[i + x];
    }

    std::ranges::sort(a, [&](auto x, auto y){
        return x[1] < y[1];
    });
    if (std::ranges::count_if(a, [&](auto p){ return p[0] > p[2]; }) != x) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i][2] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
