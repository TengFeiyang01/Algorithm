#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::map<int, int> pre, cur;
    int count = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        pre[b[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)  {
        if (i >= m) {
            cur[a[i - m]]--;
            if (cur[a[i - m]] < pre[a[i - m]]) {
                count--;
            }
        } 

        if (++cur[a[i]] <= pre[a[i]]) {
            count++;
        }

        if (count >= k and i >= m - 1) {
            ans++;
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
