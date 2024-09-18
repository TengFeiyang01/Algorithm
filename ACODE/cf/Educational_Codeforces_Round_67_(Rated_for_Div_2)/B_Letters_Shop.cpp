#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector cnt(n + 1, std::vector(26, 0));
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1];
        cnt[i][s[i - 1] - 'a']++;
    }


    int q;
    std::string t;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> t;
        std::vector need(26, 0);
        for (auto c : t) {
            need[c - 'a']++;
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            bool ok = true;
            for (int j = 0; j < 26; ++j) {
                if (cnt[mid][j] < need[j]) {
                    ok = false;
                }
            }
            if (ok) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        std::cout << r << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
