#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    	ans += abs(a[i] - b[i]);
    }
    int mnb = inf, mxa = 0;
    i64 res = ans;

    for (int i = 0; i < n; ++i) {
    	if (b[i] >= a[i]) {
            ans = std::max(ans, res + 2 * (mxa - b[i]));
            ans = std::max(ans, res + 2 * (a[i] - mnb));
            mnb = std::min(b[i], mnb);
            mxa = std::max(mxa, a[i]);
        } 
    }
    std::swap(a, b);
    for (int i = 0; i < n; ++i) {
        if (b[i] >= a[i]) {
            ans = std::max(ans, res + 2 * (mxa - b[i]));
            ans = std::max(ans, res + 2 * (a[i] - mnb));
            mnb = std::min(b[i], mnb);
            mxa = std::max(mxa, a[i]);
        } 
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
