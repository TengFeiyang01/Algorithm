#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, x;

/*
    eg: a ^ b == x 则 a ^ b ^ b == a == x ^ b
    我们可以通过寻找 x ^ nums[i] 寻找另一个数

    对于一个区间 [l, r] 如果区间内存在 i,j 使得 a[i] ^ a[j] == x
    则对于[i, r] 显然也是可以的 因此我们可以维护每一个 能够满足题意的区间的右端点 r
    dp[r] = max(dp[r - 1], mp[a[i] ^ x])
    然后依次判断当前区间是否符合题意即可
*/

void solve() {
    std::cin >> n >> m >> x;
    std::unordered_map<ll, ll> mp;
    ll dp[n + 1]{0};
    for (int i = 1; i <= n; ++i) {
        int u;
        std::cin >> u;
        dp[i] = std::max(dp[i - 1], mp[x ^ u]);       
        mp[u] = i;
    }
    while (m--) {
        ll l, r;
        std::cin >> l >> r;
        if (dp[r] >= l) std::cout << "yes\n";
        else std::cout << "no\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
