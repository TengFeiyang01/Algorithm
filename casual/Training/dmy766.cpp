#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    const int B = sqrt(n);
    std::vector<i64> a(n + 1);
    std::vector<std::vector<i64>> tag(B + 1, std::vector<i64>(B + 1));

    while (q--) {
    	int op, x, y, d;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> x >> y >> d;
    		if (x > B) {
    			for (int i = y; i <= n; i += x) {
    				a[i] += d;
    			}
    		} else {	
                tag[x][y] += d;
    		}
    	} else {
    		std::cin >> x;
    		i64 ans = a[x];
    		for (int i = 1; i <= B; ++i) {
                ans += tag[i][x % i];
    		}
    		std::cout << ans << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
