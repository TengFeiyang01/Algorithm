#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<double> f(n + 1), g(n + 1);
    f[n] = g[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
    	f[i] = f[i + 1] + double(n) / (n - i);
    	g[i] = double(i) / (n - i) * f[i] + g[i + 1] + f[i + 1] + double(n) / (n - i);
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << g[0] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
