#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, i64> pre, suf, cnt;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]]) continue;
        cnt[a[i]] = 1;
        pre[i] = 1;
    }
    
    cnt.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (cnt[a[i]]) continue;
        cnt[a[i]] = 1;
        suf[i] = 1;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        suf[i] += suf[i + 1];
        ans += pre[i] * suf[i];
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