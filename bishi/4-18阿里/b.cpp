#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 思路：必然是先通过若干次加2或者加5 加到 [y-10,y+10]附近
// 然后暴力枚举其他两个操作的次数即可 因为 +2 -3 +5 很容易凑出来 +1 -1

void solve() {
    int T;
    std::cin >> T;
    while (T--) {
    	i64 x, y, a, b, c;
    	std::cin >> x >> y >> a >> b >> c;
    	i64 ans = 1e18;

    	{
    		i64 tmp = y - x;
    		tmp /= 2;
    		for (i64 z = std::max(tmp - 10, 0LL); z <= tmp + 10; ++z) {
    			for (int i = 0; i <= 50; ++i) {
    				for (int j = 0; j <= 50; ++j) {
    					if (x + 2 * z - 3 * i + 5 * j == y) {
    						ans = std::min(ans, z * a + i * b + j * c);
    					}
    				}
    			}
    		}
    	}

    	{
    		i64 tmp = y - x;
    		tmp /= 5;
    		for (i64 z = std::max(tmp - 10, 0LL); z <= tmp + 10; ++z) {
    			for (int i = 0; i <= 50; ++i) {
    				for (int j = 0; j <= 50; ++j) {
    					if (x + 5 * z - 3 * i + 2 * j == y) {
    						ans = std::min(ans, z * c + i * b + j * a);
    					}
    				}
    			}
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
