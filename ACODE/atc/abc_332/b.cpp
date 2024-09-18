#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int k, g, m;
    std::cin >> k >> g >> m;
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
    	if (a == g) {
    		a = 0;
    	} else if (b == 0) {
    		b = m;
    	} else {
    		int x = std::min(b, g - a);
    		b -= x;
    		a += x;
    	}
    }
    std::cout << a << " " << b;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
