#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 a, b, c;
    std::cin >> a >> b >> c;
    i64 d1 = b - a, d2 = c - b;
    i64 a1 = 2 * b - c;
    //枚举等差数列的第三个数
    
    if (a1 > 0 and a1 % a == 0) {
        std::cout << "YES\n";
        return;
    }
    i64 b1 = (a + c) / 2;
    if ((a + c) % 2 == 0 and b1 % b == 0) {
        std::cout << "YES\n";
        return;
    }
    i64 c1 = 2 * b - a;
    if (c1 > 0 and c1 % c == 0) {
        std::cout << "YES\n";
        return;
    }

    std::cout << "NO\n";
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
