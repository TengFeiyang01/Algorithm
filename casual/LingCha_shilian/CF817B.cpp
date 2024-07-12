#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, i64> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    std::vector<int> b;
    for (auto [k, v] : cnt) {
        b.push_back(v);
    }
    std::ranges::sort(a);
    if (b[0] >= 3) {
    	i64 x = b[0];
    	std::cout << x * (x - 1) * (x - 2) / 6 << "\n";
    } else {
        i64 x = b[0], y = b[1];
        if (x + y >= 3) {
            if (x == 1) {
                std::cout << y * (y - 1) / 2 << "\n";
            } else {
                std::cout << y << "\n";
            }
        } else {
            std::cout << b[2] << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
