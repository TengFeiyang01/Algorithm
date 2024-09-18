#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 根据容斥原理，只含棒子的蛋的数量=棒子数-两个物品都含的蛋的数量，只含玩具的也是同理。两个物品都含的蛋的数量=棒子数+玩具数-蛋数。


void solve() {
    int n, s, t;
    std::cin >> n >> s >> t;
    std::cout << std::max(s - (s + t - n) + 1, t - (s + t - n) + 1) << "\n";
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
