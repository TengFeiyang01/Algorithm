#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    }
    std::vector<PII> ans;
    for (int i = 1; i <= n; ++i) {
    	if (a[i] == b[i]) continue;
    	else {
    		int j = i + 1;
    		while (j <= n and b[j] != a[i]) j++;
            while (j > i) {
                std::swap(b[j], b[j - 1]);
                ans.push_back({j - 1, j});
                j--;
            }
    	}
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
    	std::cout << x << " " << y  << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
