#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int l = 0, ans = -1;
    int c = 0, n = s.size(), d = 0;
    for (int r = 0; r < n; ++r) {
        if (isalpha(s[r])) {
            c++;
        } else {
            d++;
        }
        while (c > 1) {
            if (isalpha(s[l])) {
                c--;
            } else {
                d--;
            }
            l += 1;
        }
        if (c == 1 and d) {
            ans = std::max(ans, r - l + 1);
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
