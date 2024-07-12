#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 5e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<std::array<int, 3>> dp(N);
    std::vector<std::array<int, 3>> f(N);
    int cnt = 0;
    std::function<void(int)> dfs = [&](int x) {
        if (s[x] == '0') {
            dp[x][0] = f[x][0] = 1;
            return;
        }
        // 先遍历的当前结点 那么显然左子树就是 x+1
        // 右子树是 cnt+1
        dfs(++cnt);
        if (s[x] == '1') {
            dp[x][0] = std::max(dp[x + 1][1], dp[x + 1][2]) + 1;
            dp[x][1] = std::max(dp[x + 1][0], dp[x + 1][2]);
            dp[x][2] = std::max(dp[x + 1][0], dp[x + 1][1]);

            f[x][0] = std::min(f[x + 1][1], f[x + 1][2]) + 1;
            f[x][1] = std::min(f[x + 1][0], f[x + 1][2]);
            f[x][2] = std::min(f[x + 1][0], f[x + 1][1]);
        } else {
            int k = ++cnt;
            dfs(k);
            dp[x][0] = std::max(dp[x + 1][1] + dp[k][2], dp[x + 1][2] + dp[k][1]) + 1;
            dp[x][1] = std::max(dp[x + 1][0] + dp[k][2], dp[x + 1][2] + dp[k][0]);
            dp[x][2] = std::max(dp[x + 1][0] + dp[k][1], dp[x + 1][1] + dp[k][0]);
            
            f[x][0] = std::min(f[x + 1][1] + f[k][2], f[x + 1][2] + f[k][1]) + 1;
            f[x][1] = std::min(f[x + 1][0] + f[k][2], f[x + 1][2] + f[k][0]);
            f[x][2] = std::min(f[x + 1][0] + f[k][1], f[x + 1][1] + f[k][0]);
        }
    };
    dfs(0);
    std::cout << std::ranges::max(dp[0]) << " " << std::ranges::min(f[0]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
