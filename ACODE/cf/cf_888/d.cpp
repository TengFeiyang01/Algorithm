#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);

    for (i64 i = 1; i < n; ++i) {
    	std::cin >> a[i];
    }

    if (a[n - 1] > 1LL * n * (n + 1 ) / 2) {
        std::cout << "NO\n";
        return;
    }

    std::vector<int> cnt(2 * n + 1);

    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 2 * n) {
            std::cout << "No\n";
            return;
        }
        cnt[a[i] - a[i - 1]]++;
    }

    if (a[n - 1] < 1LL * n * (n + 1) / 2) {
        for (int i = 1; i <= n * 2; ++i) {
            if (cnt[i] > (i <= n)) {
                std::cout << "NO\n";
                return;
            }
        }        
        std::cout << "YES\n";
        return;
    }

    int x = std::find(cnt.begin() + 1, cnt.end(), 0) - cnt.begin();
    int y;
    for (int i = 1; i <= 2 * n; ++i) {
        if (cnt[i] > (i <= n)) {
            y = i;
            break;
        }
    }
    if (y <= x) {
        std::cout << "NO\n";
        return;
    }
    cnt[y]--;
    cnt[x]++;
    cnt[y - x]++;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] != 1) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
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
