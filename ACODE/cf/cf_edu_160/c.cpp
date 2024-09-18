#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(35);
    while (n--) {
    	i64 t, x;
    	std::cin >> t >> x;
    	if (t == 1) {
    		a[x]++;
    	} else {
    		auto b = a;
    		int ok = true;
    		for (int i = 0; i < 30; ++i) {
    			if (x >> i & 1) {
    				if (!b[i]) {
    					ok = false;
    				} else {
    					b[i]--;
    				}
    			}
                if (b[i] >= 2) {
                    b[i + 1] += b[i] / 2;
                }
    		}
    		std::cout << (ok ? "YES\n" : "NO\n");
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
