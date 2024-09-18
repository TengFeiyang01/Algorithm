#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), cnt(n + 1), st(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
        st[a[i]] = 1;
    }
    i64 ans = 0;
    
    std::vector<i64> f(n + 1);
    for (int i = n; i >= 1; --i) {
        i64 s = 0;
        for (int j = i; j <= n; j += i) {
            s += cnt[j];
            f[i] -= f[j];
            st[j] |= st[i];
        }
        f[i] += s * (s - 1) / 2;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            ans += f[i];
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