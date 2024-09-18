#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 a, b;
    std::cin >> a >> b;
    i64 area = 0, h = 0, w = 0;
    for (i64 p = 1, i = 0; i <= 30; ++i, p <<= 1) {
        if (p <= a and 4 * p <= 5 * b) {
            i64 t = std::min(b, 5 * p / 4);
            if (p * t > h * w or (p * t == h * w and h < p)) {
                h = p;
                w = t;
            }
        }
        if (p <= b and 4 * p <= 5 * a) {
            i64 t = std::min(a, 5 * p / 4);
            if (p * t > h * w or (p * t == h * w and h < t)) {
                h = t;
                w = p;
            }
        }
    }

    std::cout << h << " " << w << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
