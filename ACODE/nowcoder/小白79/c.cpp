#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    double ans = inf;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    std::vector<i64> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] + a[i];
    i64 pre = 0;
    for (int i = 0; i < k; ++i) {
        int l = i, r = l + (n - k);
    	double avg = double(pre + suf[r]) / k;
    	ans = std::min(ans, std::max(1.0 * a[r - 1], avg) - std::min(1.0 * a[l], avg));
        pre += a[l];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}