#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans = 0; 

    auto get = [&](int x) {
        std::vector<int> tmp;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                tmp.push_back(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            tmp.push_back(x);
        }
        return tmp;
    };

    std::unordered_map<int, int> st; 
    for (int l = 0, r = 0; r < n; r++) {
        bool ok = true; 
        auto tmp = get(a[r]);

        for (auto p : tmp) {
            st[p]++;
            if (st[p] > 1) { 
                ok = false;
            }
        }

        while (!ok) {
            auto remove = get(a[l]);
            for (auto p : remove) {
                st[p]--;
            }
            l++; 
            ok = true;
            for (auto p : tmp) {
                if (st[p] > 1) {
                    ok = false;
                    break;
                }
            }
        }

        ans = std::max(ans, r - l + 1);
    }

    std::cout << ans << '\n'; 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
