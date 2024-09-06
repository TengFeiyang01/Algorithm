#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::map<std::pair<int, int>, int> cnt;
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	int g = std::__gcd(i, a[i]);
    	ans += cnt[{i / g, a[i] / g}];
    	cnt[{i / g, a[i] / g}]++;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
