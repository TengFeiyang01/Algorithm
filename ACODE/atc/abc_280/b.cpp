#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = n - 1; i > 0; --i) {
    	a[i] -= a[i - 1];
    }
    for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
