#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int row = 0;
    for (int col = 63; col >= 0 and row < n; --col) {
        for (int i = row; i < n; ++i) {
            if (a[i] >> col & 1) {
                std::swap(a[row], a[i]);
                break;
            }
        }
        if (!(a[row] >> col & 1)) continue;
        for (int i = 0; i < n; ++i) {
            if (i == row) continue;
            if (a[i] >> col & 1) {
                a[i] ^= a[row];
            }
        }
        ++row;
    }
    i64 ans = 0;
    for (int i = 0; i < row; ++i) {
        ans ^= a[i];
    }
    std::cout << ans << "\n";
}

#if 0
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), p(64);
    auto insert = [&](i64 x) {
    	for (int i = 63; i >= 0; --i) {
    		if (!(x >> i)) continue;
    		if (!p[i]) {
    			p[i] = x;
    			break;
    		}
    		x ^= p[i];
    	}
    };
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	insert(a[i]);
    }
    i64 ans = 0;
    for (int i = 63; i >= 0; --i) {
    	ans = std::max(ans, ans ^ p[i]);
    }
    std::cout << ans << "\n";
}
#endif

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
