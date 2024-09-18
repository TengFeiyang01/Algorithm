#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
    	int x, ans = 0;
    	std::cin >> x;
    	int d = x % 10;
    	x /= 10;
    	int c = x % 10;
    	x /= 10;
    	int b = x % 10;
    	x /= 10;
    	int a = x;
    	if (a == b and c == d and a != c) {
    		ans += 3;
    	} else if (a == c and b == d and a != b) {
    		ans += 2;
    	} 
    	
    	if (a % 2 == b % 2 and b % 2 == c % 2 and c % 2 == d % 2) {
    		ans += 2;
    	}
    	if (a + 1 == b and b + 1 == c and c + 1 == d) {
    		ans += 10;
    	}

    	if (a - 1 == b and b - 1 == c and c - 1 == d) {
    		ans += 10;
    	}
    	if (a == 3 or a == 6) {
    		ans++;
    	}
    	if (b == 3 or b == 6) {
    		ans++;
    	}
    	if (c == 3 or c == 6) {
    		ans++;
    	}
    	if (d == 3 or d == 6) {
    		ans++;
    	}
    	std::vector<int> p{a, b, c, d};
    	std::sort(p.begin(), p.end());
    	if (p[3] - p[0] == 0) {
    		ans += 8;
    	} else {
    		if (p[3] - p[1] == 0 or p[2] - p[0] == 0) {
    			ans += 4;
    		}
    	}
	    std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
