#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] < 0) {
            a[i] = -a[i];
        }
    }
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (auto x : a) {
        if (k >= x) {
            ans++;
            k -= x;
        } else {
            break;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
