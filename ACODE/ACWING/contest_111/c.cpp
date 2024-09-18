#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;
    std::vector<int> a(m);
    int s = 0, tot = 0;
    h--;
    for (int i = 0; i < m; ++i) {
    	std::cin >> a[i];
        tot += a[i];
        if (i != h) s += a[i];
    }
    if (tot < n) {
        std::cout << "-1\n";
    } else {
        if (n - 1 - s > 0) {
            std::cout << 1 << "\n";
        } else {
            double ans = 1;
            for (int i = 0; i < n - 1; ++i) {
                ans *= double(s - i) / (tot - i - 1);
            }
            std::cout << 1.0 - ans << "\n";
        }
    }
    

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
