#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), st(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	--a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	i64 x = i, cnt = 0;
    	while (!st[x]) {
    		st[x] = 1;
    		cnt++;
    		x = a[x];
    	}
    	ans += cnt * cnt;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
