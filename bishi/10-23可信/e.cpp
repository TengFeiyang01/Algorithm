#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
    }
    i64 l = 0, r = 1e9;

    auto check = [&](i64 p) {
        i64 cnt = 0;
        for (int i = 0; i < n; ++i) {
            // 必须要买的
            if (a[i][1] >= p) {
                cnt += (a[i][1] - p + 1);
            } 
        }
        return cnt <= p;
    };

    while (l < r) {
        i64 mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    i64 ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i][1] >= l) {
            cnt += (a[i][1] - l + 1);
            ans += (a[i][1] - l + 1) * a[i][0];
            a[i][1] = l - 1;
        }
    }
    
    cnt = l - cnt;
    std::cout << l << "\n";

    std::ranges::sort(a);
    for (int i = 0; i < n; ++i) {
        if (cnt >= a[i][1]) {
            cnt -= a[i][1];
            ans += a[i][0] * a[i][1];
        } else {
            ans += cnt * a[i][0];
            break;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
