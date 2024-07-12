#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::bitset<N> b;
    std::vector<int> a(n);
    b[1] = 1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        b |= (b >> (i + 1)) << (i + 1 + a[i]);
    }

    i64 ans = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        if (i < n) sum += a[i];
    	if (b[i + 1] == 1) ans = std::max(ans, sum - i);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
