#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, p;
    std::cin >> n >> p;
    std::vector<std::array<i64, 2>> a(n);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][1];
    }
    std::sort(a.begin(), a.end(), [&](auto &x, auto &y){
    	return x[1] < y[1];
    });
    
    int i = 0, j = 0;
    std::vector<int> st(n);

    for (int i = 0; i < n; ++i) {
        if (!st[i]) {
            ans += p;
        }
        j = std::max(j, i);
        st[i] = true;
        if (a[i][1] < p) {
            int cnt = 0;
            while (cnt < a[i][0] and j < n - 1) {
                j++;
                cnt++;
                ans += a[i][1];
                st[j] = true;
            }
        }
        if (j == n - 1) break;
    }

    std::cout << ans << "\n";
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