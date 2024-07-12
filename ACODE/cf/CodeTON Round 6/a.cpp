#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    //mex=k ==> 0 1 2 2 2
    int ans = k * (k - 1) / 2;
    if (k - x > 1 or n < k) {
    	std::cout << -1 << "\n";
    } else {
        int cnt = n - k;
        int mx = 0;
        if (k == x) {
            mx = x - 1;
        } else {
            mx = x;
        }
        std::cout << ans + mx * cnt << "\n";
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