#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, a, b;
    double x, y;
    std::cin >> n >> a >> b >> x >> y;
    std::vector<double> p(n);
    double tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        tot += p[i];
    }
    x = 100 - x;
    int mx = std::min(a + b, n);
    std::sort(p.begin(), p.end(), std::greater<double>());
    for (int i = 0; i < mx; ++i) {
        tot -= std::min(p[i], y);
    }

    std::priority_queue<double, std::vector<double>, std::greater<double>> pq;

    for (int i = 0; i < mx; ++i) {
        pq.push(std::min(p[i], y) - (p[i] * x / 100));
    }

    double ans = inf;
    int mna = (a + b > n) ? (std::max(0, a - (a + b - n))) : a;
    if (mna == 0) {
        ans = tot;
    }

    for (int i = 1; i <= a; ++i) {
        tot += pq.top();
        pq.pop();
        if (i >= mna) {
            ans = std::min(ans, tot);
        }
    }

    std::cout << std::fixed << std::setprecision(18) << ans << "\n";
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
