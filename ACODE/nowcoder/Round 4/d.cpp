#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 a, b;
    std::cin >> a >> b;

    std::map<i64, i64> cnt;

    for (i64 i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            while (a % i == 0) {
                a /= i;
                cnt[i]++;
            }
        }
        
    }
    if (a > 1) cnt[a]++;
    for (i64 i = 2; i * i <= b; ++i) {
        if (b % i == 0) {
            while (b % i == 0) {
                b /= i;
                cnt[i]++;
            }
        }
    }
    if (b > 1) cnt[b]++;
    int m = 1;
    for (auto &[p, t] : cnt) m *= (t + 1);
    std::vector<i64> ans(m, 1);
    m = 1;
    for (auto &[p, t] : cnt) {
        i64 pw = 1;
        for (int i = 1; i <= t; ++i) {
            pw *= p;
            for (int j = 0; j < m; ++j) ans[m * i + j] = ans[j] * pw;
        }
        m *= t + 1;
    }
    std::sort(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for (auto x: ans) std::cout << x << " ";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
