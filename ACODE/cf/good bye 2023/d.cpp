#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "1\n";
        return ;
    }
    std::cout << "196";
    for (int i = n - 3; i; i --) std::cout << "0";
    std::cout << "\n";
 
    for (int i = 1; i < n; i += 2) {
        int cnt = 3;
        std::cout << "9";
        for (int k = 1; k <= i / 2; k ++) std::cout << "0", cnt ++;
        std::cout << "6";
        for (int k = 1; k <= i / 2; k ++) std::cout << "0", cnt ++;
        std::cout << "1";
        for (int k = cnt; k < n; k ++) std::cout << "0";
        std::cout << "\n";
    }
 
    for (int i = 1; i < n; i += 2) {
        int cnt = 3;
        std::cout << "1";
        for (int k = 1; k <= i / 2; k ++) std::cout << "0", cnt ++;
        std::cout << "6";
        for (int k = 1; k <= i / 2; k ++) std::cout << "0", cnt ++;
        std::cout << "9";
        for (int k = cnt; k < n; k ++) std::cout << "0";
        std::cout << "\n";
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
