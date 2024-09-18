#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, s, tot = 0;
    std::cin >> n >> s;
    s -= n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	--a[i];
    	tot += a[i];
    }
   	// 当前骰子最大能多少
   	for (auto x : a) {
   		i64 mx = std::min(x, s);
   		i64 mn = std::max(x - (tot - s), 0ll);
   		std::cout << x - mx + mn << " ";
   	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

// tot - x - s >= 0 => y可以取0
// tot - x - s < 0 y最小得取 -(tot - x - s) = x - tot + s