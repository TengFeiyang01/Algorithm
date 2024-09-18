#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    int now = n - 1, cnt = 1, ok = 1;
    //左移到b 那么右移还原 那么右移的次数是b[now] 移动后新的末尾就是(now-b[now]+n) % n
    while (cnt <= std::min(n, k)) {
        cnt++;
        if (b[now] > n) {
            ok = 0;
            break;
        }
        now = (now - b[now] + n) % n;
    }
    std::cout << (ok ? "Yes\n" : "No\n");
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
