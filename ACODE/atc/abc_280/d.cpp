#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, k, ans = 1;
    std::cin >> k;
    int ok = 1;
    for (i64 i = 2; i * i <= k; ++i) {
        i64 a = 0;
        while (k % i == 0) k /= i, a++;
        n = 0;
        //k 中有 a 个i 答案至少包含 a 个i
        while (a > 0) {
            n += i;
            i64 x = n;
            while (x % i == 0) x /= i, a--;
        }
        ans = std::max(ans, n);
    }
    ans = std::max(ans, k);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
