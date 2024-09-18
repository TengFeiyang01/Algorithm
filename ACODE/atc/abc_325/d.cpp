#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> seg(n);
    for (int i = 0; i < n; ++i) {
        i64 t, d;
        std::cin >> t >> d;
        seg[i] = {t, t + d};
    }

    std::ranges::sort(seg);
    std::priority_queue<i64, std::vector<i64>, std::greater<>> q;
    int ans = 0, i = 0;
    i64 t = 0;
    while (true) {
        if (q.empty()) {
            if (i == n) break;
            t = std::max(t, seg[i].first);
        }
        while (i < n and seg[i].first <= t) {
            q.push(seg[i].second);
            i++;
        }

        while (!q.empty() and q.top() < t) {
            q.pop();
        }
        if (!q.empty()) {
            ans++;
            q.pop();
        }
        t++;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}