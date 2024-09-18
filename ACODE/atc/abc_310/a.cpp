#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, p, q;
    std::cin >> n >> p >> q;
    std::vector<int> d(n);
    for (int &i : d) std::cin >> i;
    int ans = p;		
	for (auto x : d) {
		ans = std::min(ans, q + x);
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
