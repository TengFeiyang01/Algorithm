#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }

    // 贪心
    // std::multiset<int> vl, vr;

    // for (int i = 3; i <= n; ++i) vr.insert(a[i] - i);
    // vl.insert(a[1] + 1);
    // int ans = 0;
    // for (int i = 2; i < n; ++i) {
    //     auto itl = vl.rbegin(), itr = vr.rbegin();
    //     ans = std::max(ans, (*itl + *itr + a[i]));
    //     vl.insert(a[i] + i);
    //     vr.erase(vr.find(a[i + 1] - i - 1));
    // }
    // std::cout << ans << "\n";

    //DP
    // std::vector<int> dp1(n + 1), dp2(n + 2);
    // int ans = 0;
    // for (int i = 1; i <= n; ++i) {
    //     dp1[i] = std::max(dp1[i - 1], a[i] + i);
    //     dp2[i] = std::max(dp2[i - 1], dp1[i - 1] + a[i]);
    //     if (i >= 3) {
    //         ans = std::max(ans, dp2[i - 1] + a[i] - i);
    //     }
    // }
    // std::cout << ans << "\n";


    //前后缀分解 
    int ans = 0;
    std::vector<int> pre(n + 1), suf(n + 2);
    pre[0] = suf[n + 1] = -inf;
    for (int i = 1; i <= n; ++i) pre[i] = std::max(pre[i - 1], a[i] + i);
    for (int i = n; i >= 1; --i) suf[i] = std::max(suf[i + 1], a[i] - i);
    for (int i = 2; i < n; ++i) {
        ans = std::max(ans, pre[i - 1] + suf[i + 1] + a[i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
