#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> S(6);
    i64 ans = 0;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        S[s.size()].push_back(s);
    }
    for (int len = 2; len <= 10; len += 2) {
        int mid = len >> 1;
        for (int l = 1; l <= 5; ++l) {
            int r = len - l;
            if (1 > r or 5 < r) continue;
            std::map<int, int> pre, suf;
            // ls - x == r == ls - x ==> r + x == ls
            // rs - x == l == rs - x ==> l + x == rs
            for (auto s : S[l]) {
                int x = 0;
                for (int i = 0; i < std::min(mid, l); ++i) {
                    x += s[i] - '0';
                }                                                                                                                                                    
                for (int i = mid; i < l; ++i) {
                    x -= s[i] - '0';
                }
                if (x > 0) {
                    pre[x]++;
                }
            }
            for (auto s : S[r]) {
                int x = 0;
                for (int i = std::max(r - mid, 0); i < r; ++i) {
                    x += s[i] - '0';
                }
                for (int i = 0; i < r - mid; ++i) {
                    x -= s[i] - '0';
                }
                if (x > 0) {
                    suf[x]++;
                }
            }
            for (int i = 0; i < 50; ++i) {
                ans += pre[i] * 1LL * suf[i];
            }
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
