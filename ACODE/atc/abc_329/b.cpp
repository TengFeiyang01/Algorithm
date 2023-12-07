#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int f = 0, s = 0;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x > f) {
    		s = f;
    		f = x;
    	} else if (x != f and x > s) {
    		s = x;
    	}
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
