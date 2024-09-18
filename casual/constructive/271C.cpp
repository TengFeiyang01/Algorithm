#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n < 3 * k) {
        std::cout << "-1\n";
        return;
    }
    std::vector<int> a(n, 1);
    for (int i = 1; i < k * 2; i += 2) {
    	a[i] = (i + 1) / 2;
    	a[i - 1] = a[i];
    }
    for (int i = 2 * k; i < 3 * k; ++i) {
    	a[i] = i - 2 * k + 1;
    }
    for (int x : a) std::cout << x << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
