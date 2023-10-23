#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector pos(n, std::vector<int>());
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[--a[i]].push_back(i);
    }
    int m = n >> 1;
    
    i64 ans = 1LL * m * (m + 1) * (m * 4 + n % 2 * 6 - 1) / 6;

    for (auto &p : pos) {
    	int l = 0, r = p.size() - 1;
    	while (l < r) {
    		if (p[l] + p[r] < n) {
    			ans -= 1LL * (p[l] + 1) * (r - l);
    			l++;
    		} else {
    			ans -= 1LL * (n - p[r]) * (r - l);
    			r--;
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
