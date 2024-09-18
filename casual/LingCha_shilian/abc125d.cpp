#include <bits/stdc++.h>
 
using i64 = long long;
const i64 inf = 1e15;

void solve() {
    int n;
    std::cin >> n;
    int neg = 0;
    i64 s = 0, v = 0, mn;
    for (int i = 0; i < n; ++i) {
        std::cin >> v;
        if (v < 0) {
            neg ^= 1;
            v = -v;
        }
        s += v;
        mn = std::min(mn, v);
    }
    std::cout << s - mn * neg * 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}