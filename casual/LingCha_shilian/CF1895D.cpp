#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 1; i < n; ++i) {
    	std::cin >> a[i];
        a[i] ^= a[i - 1];
    }


    std::vector<int> b(n);
    for (int j = 0; j < 30; ++j) {
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt += i >> j & 1;
            cnt -= a[i] >> j & 1;
        }
        if (cnt) {
            b[0] |= 1 << j;
        }
    }
    for (int i = 0; i < n; ++i) {
    	if (i) {
            b[i] = b[0] ^ a[i];
        }
        std::cout << b[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}