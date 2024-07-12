#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a, b, n;
    std::cin >> a >> b >> n;
    std::vector<int> c(n), p(n);

    int cur = a, x = 0;
    std::vector<int> d{a, b};

    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (p[i] == 0) {
            c[i] = x;
            cur--;
            if (cur == 0) {
                x ^= 1;
                cur = d[x]; 
            }
        } else if (p[i] == -1) {
            cur -= 1 + (cur > 1);
            if (d[x] > 1) {
                d[x]--;
            }
            c[i] = x;
            if (cur == 0) {
                x ^= 1;
                cur = d[x];
            }
        } else if (p[i] == 1) {
            d[x]++;
            c[i] = x;
        }
    }   
    for (int i = 0; i < n; ++i) {
        std::cout << char('A' + c[i]);
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
