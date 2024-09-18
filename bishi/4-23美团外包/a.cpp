#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k, s = 0;
    std::cin >> n >> m >> k;
    std::vector<int> a(m), oddmx(m), evenmx(m), oddmn(m, inf), evenmn(m, inf); 
    for (int i = 0; i < m; ++i) {
        int odd = 0, even = 0;
        for (int j = 0; j < k; ++j) {
            int x;
            std::cin >> x;

            evenmx[i] = std::max(evenmx[i], x);
            evenmn[i] = std::min(evenmn[i], x);
            if (x & 1) {
                odd++;
            } else {
                even++;
            }
        }
        if (odd and even) {
            a[i] = -1;
            s += oddmn[i];
        } else if (odd) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }   

    if (s > n) {
        std::cout << -1 << "\n";
    } else {
        for (int i = 0; i < m; ++i) {
            if (a[i] == -1) {
                std::cout << "Even";
                n -= oddmx[i];
            } else if (a[i] == 0) {
                std::cout << "Even";
                n += evenmn[i];
            } else {
                if (n >= evenmx[i]) {
                    std::cout << "Even";
                    n -= evenmx[i];
                } else {
                    n += oddmn[i];
                    std::cout << "Odd";
                }
            }
            std::cout << " \n"[i == m - 1];
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