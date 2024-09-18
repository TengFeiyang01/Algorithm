#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1000000007;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<std::array<i64, 10>> f(n);
    f[0][s[0] - '0'] = 1;
    for (int i = 1; i < n; ++i) {
    	f[i] = f[i - 1];
    	f[i][s[i] - '0'] = (std::accumulate(f[i - 1].begin(), f[i - 1].end(), 1L) - f[i - 1][s[i] - '0']) % mod;
    }
    std::cout << std::accumulate(f[n - 1].begin(), f[n - 1].end(), 0L) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
