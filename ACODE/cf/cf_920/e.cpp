#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int h, w, xa, xb, ya, yb;
    std::cin >> h >> w >> xa >> ya >> xb >> yb;
    int del = xb - xa;
    if (xa >= xb) {
        // 不可能相遇
		std::cout << "Draw\n";    	
    } else if ((xb - xa) % 2) {
        // 最后一步是 alice 走
    	int la = std::max(1, ya - del / 2), ra = std::min(w, ya + del / 2);
    	int lb = std::max(1, yb - del / 2), rb = std::min(w, yb + del / 2);
    	if (la <= lb + 1 and ra >= rb - 1) {
    		std::cout << "Alice\n";
    	} else {
			std::cout << "Draw\n";    	
    	}
    } else {
        // 最后一步是 Bob 走
    	int la = std::max(1, ya - del / 2), ra = std::min(w, ya + del / 2);
    	int lb = std::max(1, yb - (del - 1) / 2), rb = std::min(w, yb + (del - 1) / 2);
    	if (lb <= la + 1 and rb >= ra - 1) {
    		std::cout << "Bob\n";
    	} else {
			std::cout << "Draw\n";    	
    	}
    }
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
