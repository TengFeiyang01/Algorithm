#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;



void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	a[i][0] -= x;
    	a[i][1] = i + 1;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> ans;
    int x = a.back()[0];
    for (int i = n - 1; i >= 0; --i) {
    	if (a[i][0] == x) {
    		ans.push_back(a[i][1]);
    	}
    }
    std::cout << ans.size() << "\n";
    std::sort(ans.begin(), ans.end());
    for (int x : ans) {
    	std::cout << x << " ";
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
