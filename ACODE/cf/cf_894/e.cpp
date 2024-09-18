#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m, d;
    std::cin >> n >> m >> d;

    std::vector<i64> a(n);

    i64 ans = 0, sum = 0;    
    std::priority_queue<int, std::vector<int>, std::greater<int>> h;

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        if (a[i] > 0) {
            h.push(a[i]);
            sum += a[i];
        }
        if (h.size() > m) {
            sum -= h.top();
            h.pop();
        }
        ans = std::max(ans, sum - 1LL * d * (i + 1));
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