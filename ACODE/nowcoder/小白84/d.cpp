#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::string x;
    std::cin >> n >> q;
    std::cin >> x;
    x = "0" + x + "0";
    int sum = 0;
    bool flag = false;

    for (int i = 1; i < x.size(); ++i) {
        if (!flag && x[i] == '1') {
            sum++;
            flag = true;
        } else if (x[i] == '0') {
            flag = false;
        }
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;

        if (x[l - 1] == x[r + 1] || x[l] == x[r]) {
            std::cout << sum << std::endl;
        } else {
            if (x[l - 1] != x[l]) {
                std::cout << sum - 1 << std::endl;
            } else {
                std::cout << sum + 1 << std::endl;
            }
        }
    }
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
