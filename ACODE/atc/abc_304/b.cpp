#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(8, 1);
    for (int i = 1; i < 8; ++i) a[i] = a[i - 1] * 10;
    int len = std::to_string(n).size() - 3;

    if (n <= 999) {
    	std::cout << n << "\n";
    } else {
    	std::cout << (n / a[len]) * a[len] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
