#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::string s;
    std::cin >> s;
    n = s.size();
    std::cin >> m;
    std::string l, r;
    std::cin >> l >> r;

    //pos[i][j] i之后的第一次出现的j的位置
    std::vector<std::vector<int>> pos(n, std::vector<int>(10, n + 1));
    auto cur = pos[0];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) pos[i][j] = cur[j];
        cur[s[i] - '0'] = i;
    }


    int now = -1;
    for (int j = l[0] - '0'; j <= r[0] - '0'; ++j)
        now = std::max(now, cur[j]);
    if (now == n + 1) {
        std::cout << "YES\n";
        return;
    }
    for (int i = 1; i < m; ++i) {
        int mx = 0;
        for (int j = l[i] - '0'; j <= r[i] - '0'; ++j) {
            mx = std::max(mx, pos[now][j]);
        }
        now = mx;
        if (now == n + 1) {
            std::cout << "YES\n";
            return;
        }
    }
    if (now < n) std::cout << "NO\n";
    else std::cout << "NO\n";

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
