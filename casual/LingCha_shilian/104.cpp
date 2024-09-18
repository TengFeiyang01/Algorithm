#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    i64 s = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    i64 ans = 0, tmp = s;
    int len = 0;
    while (tmp) {
        len++;
        tmp >>= 1;
    }

    for (i64 i = 1LL << len; i > 0; i >>= 1) {
    	i64 cnt = 0;
    	for (int l = 0; l < n; ++l) {
    		i64 now = 0;
    		for (int r = l; r < n; ++r) {
    			now += a[r];
    			if ((now & i) && (now & ans) == ans) {
    				cnt++;
    			}
    		}
    	}
    	if (cnt >= k) {
    		ans |= i;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}