#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::array<int, 3> a[n];
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][1] >> a[i][0] >> a[i][2];
    } 
    std::sort(a, a + n, [](auto &a, auto &b) { return a[0] < b[0]; }); 
    std::vector<int> f(n + 1);
    for (int i = 0; i < n; ++i) {
        int j = std::upper_bound(a, a + i, std::array<int, 3>{a[i][1], INT_MAX}) - a;
        f[i + 1] = std::max(f[i], f[j] + a[i][2]);
    }
    std::cout << f[n] << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
