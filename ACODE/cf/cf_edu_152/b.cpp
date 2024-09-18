#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::map<int, std::vector<int>> a;

    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x % k == 0) {
            std::cout << i + 1 << " ";
        } else {
            a[-(x % k)].push_back(i + 1);
        }
    }
    for (auto[_, v] : a) {
        for (auto x : v) {
            std::cout << x << " ";
        }
    }

	std::cout << "\n";
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
