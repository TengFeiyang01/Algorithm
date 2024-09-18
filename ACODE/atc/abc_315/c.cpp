#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> a;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	a[x].push_back(y);
    }
    int ans = 0;
    PII pre = {-1, -1};
    std::vector<int> f;
    for (auto [x, v] : a) {
    	std::sort(v.begin(), v.end(), std::greater<int>());
    	if (v.size() >= 2) {
    		ans = std::max(ans, v[0] + v[1] / 2);
    	} 
    	f.push_back(v[0]);
    	
    }
    std::sort(f.begin(), f.end(), std::greater<int>());
    if (f.size() >= 2) {
    	ans = std::max(ans, f[0] + f[1]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
