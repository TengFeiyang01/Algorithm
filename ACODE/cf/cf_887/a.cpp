#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &i : a) std::cin >> i;
	auto b = a;
	std::sort(b.begin(), b.end());
	if (a != b) {
		std::cout << "0\n";
		return;
	}
	
	int ans = inf;
	for (int i = 1; i < n; ++i) {
		ans = std::min(ans, (a[i] - a[i - 1]) / 2 + 1);
	}
	std::cout << ans << "\n";
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
