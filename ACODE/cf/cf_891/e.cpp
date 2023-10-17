#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    std::vector<i64> ans(n), s(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    	a[i][1] = i;
    }
    std::sort(a.begin(), a.end());
    s[0] = a[0][0];
    for (int i = 1; i < n; ++i) {
    	s[i] = s[i - 1] + a[i][0];
    }

    for (int i = 0; i < n; ++i) {
        int x = a[i][0];
        ans[a[i][1]] = s[n - 1] - s[i] - 1LL * (n - i - 1) * a[i][0];
        if (i) {
            ans[a[i][1]] += 1LL * x * i - s[i - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] + n << " \n"[i == n - 1];
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
