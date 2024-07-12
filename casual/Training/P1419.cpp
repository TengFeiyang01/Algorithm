#include <bits/stdc++.h>

void solve() {
    int n, s, t;
    std::cin >> n >> s >> t;
    std::vector<double> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    /*
        二分最大值

        妙点一： check时，将所有数减去x，从而使得子段和平均值是否大于x转换为->是否存在一个子段和大于0
        妙点二： 找符合条件的子段最大值，我们可以使用单调队列
    */

    auto check = [&](double x) {
        sum[0] = 0.0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i] - x;
        }
        std::deque<int> q;
        for (int i = s, p = 0; i <= n; ++i, ++p) {
            while (q.size() and sum[p] < sum[q.back()]) q.pop_back();
            q.push_back(p);
            
            if (q.size() and q.front() < i - t) q.pop_front();
            if (q.size() and sum[i] - sum[q.front()] >= 0) return true;
        }
        return false;
    };
    
    const double eps = 1e-5;
    double l = -10000, r = 10000;

    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    printf("%.3lf\n", l);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
