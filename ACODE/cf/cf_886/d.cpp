#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int ans = 0, left = 0;
    
    for (int i = 0, pre = 0, cnt = 0; i < n; ++i) {
        if (a[i] - a[pre] > k) {
            cnt = 1;
        } else {
            cnt++;          
        }
        pre = i;
        ans = std::max(ans, cnt);
    }

    std::cout << std::max(0, n - ans) << "\n";
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
