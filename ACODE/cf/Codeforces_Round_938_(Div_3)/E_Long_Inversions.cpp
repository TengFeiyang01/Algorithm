#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    auto check = [&](int k) {
        int c = 0;
        std::vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            if (f[i]) {
                c ^= 1;
            }

            int x = s[i] - '0';
            x ^= c;
            
            if (x == 0) {
                if (i + k > n) return false;
                c ^= 1;
                if (i + k < n) f[i + k] = 1;
            }
        }
        return true;
    };
    for (int i = n; i >= 1; --i) {
        if (check(i)) {
            std::cout << i << "\n";
            return;
        }
    }
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
