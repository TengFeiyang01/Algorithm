#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int M, D;
    std::cin >> M >> D;
    int y, m, d;
    std::cin >> y >> m >> d;
    if (d == D) {
    	d = 1;
    	if (m == M) {
            m = 1;
            y++;
    	} else {
    		m++;
    	}
    } else {
    	d++;
    }
    std::cout << y << " " << m << " " << d << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}