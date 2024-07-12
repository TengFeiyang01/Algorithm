#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<double> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto check = [&](double x) {
    	bool ok = true;
    	double s = 0, mn = inf;
    	std::vector<double> pre(n + 1);
    	for (int i = 0; i < n; ++i) {
    		s += a[i] - x;
    		pre[i + 1] = s;
    		if (i - m + 1 >= 0) {
    			mn = std::min(mn, pre[i - m + 1]);
    			if (s >= mn) {
    				return true;
    			}
    		}
    	}
    	return false;
    };


    double l = 0, r = 1e13;
    for (int i = 0; i < 100; ++i) {
    	double mid = (l + r) / 2;
    	if (check(mid)) {
    		l = mid;
    	} else {
    		r = mid;
    	}
    }

    std::cout << std::fixed << std::setprecision(3) << l << "\n";
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
