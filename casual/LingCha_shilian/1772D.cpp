#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int l = 0, r = inf;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            r = std::min(r, (a[i] + a[i + 1]) / 2);
        } else if (a[i] > a[i + 1]) {
            l = std::max(l, (a[i] + a[i + 1] + 1) >> 1);
        }
    }
    if (l > r) {
        std::cout << "-1\n";
    } else {
        std::cout << l << "\n";
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
	