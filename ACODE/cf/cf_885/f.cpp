#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int ans = 0;
    for (int i = n / 2; i >= 1; i /= 2) {
        std::vector<int> b(n);
        for (int j = 0; j < n; ++j)
            b[j] = a[j] ^ a[(j + i) % n];
        int zero = std::ranges::count(b, 0);
        if (zero != n) {
            a = b;
            ans += i;
        }
    }
    int zero = std::ranges::count(a, 0);
    std::cout << ans + (zero != n) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
