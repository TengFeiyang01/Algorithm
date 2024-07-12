#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int mx, cnt;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x > mx) {
    		cnt = 1;
    		mx = x;
    	} else if (mx == x) {
    		cnt++;
    	} 
    }
    std::cout << n - cnt << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
