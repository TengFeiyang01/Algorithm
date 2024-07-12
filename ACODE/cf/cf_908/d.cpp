#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    }
    std::sort(b.begin(), b.end(), std::greater());

    int j = 0;
    for (int x : a) {
        while (j < m and b[j] >= x) {
            std::cout << b[j++] << " ";
        }
        std::cout << x << " ";
    }
    while (j < m) {
        std::cout << b[j++] << " ";
    }
    std::cout << "\n";
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
