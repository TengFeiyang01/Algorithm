#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	ans = 0;
    	for (int j = 0; j < 7; ++j) {
    		int x;
    		std::cin >> x;
    		ans += x;
    	}
    	std::cout << ans << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	solve();

    return 0;
}