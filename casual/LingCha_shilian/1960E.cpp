#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k;
    std::vector<int> a(n);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	ans += a[i] / k;
        a[i] %= k;
    }
    std::ranges::sort(a);
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] >= k) {
            ans++;
            j--;
        }
        i++;
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