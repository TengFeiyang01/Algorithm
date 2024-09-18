#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, h, k;
    std::cin >> n >> h >> k;
    std::vector<std::array<i64, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    int m;
    std::cin >> m;
    std::vector<i64> queries(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> queries[i];
    }
    auto f = [&](i64 x, i64 y) ->i64 {
        if (x % 4 == 0) {
            return (x / 4) * 3LL * y - y;
        } else {
            return (x / 4) * 3LL * y + std::max(((x % 4) - 2) * y, 0LL);
        }
    };

    //(x - 1) * y
    std::sort(queries.begin(), queries.end());

    std::sort(a.begin(), a.end(), [&](auto &x, auto &y){
        return f(x[0], x[1]) < f(y[0], y[1]);
    });   

    std::vector<i64> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = f(a[i][0], a[i][1]);
        if (i) s[i] += s[i - 1];
    }
    


    for (int i = 0; i < m; ++i) {
        i64 cur = h + queries[i] * k;
        int cnt = std::lower_bound(s.begin(), s.end(), cur) - s.begin();
        std::cout << cnt << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
