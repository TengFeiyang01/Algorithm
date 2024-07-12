#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    std::sort(a.begin(), a.end());
    int cnt = std::count(a.begin(), a.end(), 0);

    if (cnt >= (n + 1) / 2) {
        std::cout << "Dog\n";
    } else {
        if (n == 1) {
            if (a[0] % 2) {
                std::cout << "Dog\n";
            } else {
                std::cout << "Cat\n";
            }
            return;
        }

        if (n == 2) {
            if (a[0] + 1 == a[1]) {
                std::cout << "Cat\n";
            } else {
                std::cout << "Dog\n";
            }
            return;
        }

        int need = n - (n + 1) / 2 + 1;
        s -= need;
        if (s % 2 == 0) {
            std::cout << "Dog\n";
        } else {
            std::cout << "Cat\n";
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
