#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 a, b;
    std::cin >> a >> b;
    if (a < b) std::swap(a, b);
    i64 ans = 0;

    std::function<i64(i64, i64)> dfs = [&](i64 x, i64 y) ->i64 {
    	if (x < y) std::swap(x, y);
    	if (x == 0 or y == 0) return 0;
    	return (x - y) / y + dfs(x % y, y) + 1;
    };

    std::cout << dfs(a, b) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}