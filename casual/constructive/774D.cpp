#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    --l, --r;
    std::map<int, int> cnt;
    for (int i = l; i <= r; ++i) {
        cnt[a[i]]++;
    }

    for (int i = l; i <= r; ++i) {
        if (--cnt[b[i]] == 0) {
            cnt.erase(b[i]);
        }
    }
    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (i >= l and i <= r) continue;
        if (a[i] != b[i]) {
            ok = 0;
        }
    }

    std::cout << ((ok and cnt.empty()) ? "TRUTH" : "LIE");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
