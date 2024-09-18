#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<double> a, pos, neg; 
    for (int i = 0; i < n; ++i) {
    	double x;
    	std::cin >> x;
    	if (x > 0) {
    		pos.emplace_back(x);
    	} else {
    		neg.emplace_back(x);
    	}
    }
    std::ranges::sort(neg);
    std::ranges::sort(pos);
    int i = 0, j = neg.size() - 1, cnt = 0;
    while (i <= j and cnt <= 3) {
    	a.emplace_back(neg[i++]);
    	if (i < j) {
    		a.emplace_back(neg[j--]);
    	}
    	cnt++;
    }
    i = 0, j = pos.size() - 1, cnt = 0;
    while (i <= j and cnt <= 3) {
    	a.emplace_back(pos[i++]);
    	if (i <= j) {
    		a.emplace_back(pos[j--]);
    	}
    	cnt++;
    }	
    int m = a.size();

    double mx = -inf, mn = 1e13;
    for (int i = 0; i < m; ++i) {
    	for (int j = i + 1; j < m; ++j) {
    		for (int k = j + 1; k < m; ++k) {
    			mx = std::max(mx, (a[i] + a[j] + a[k]) / (a[i] * a[j] * a[k]));
    			mn = std::min(mn, (a[i] + a[j] + a[k]) / (a[i] * a[j] * a[k]));
    		}
    	}
    }
    std::cout << std::fixed << std::setprecision(12) << mn << "\n";
    std::cout << std::fixed << std::setprecision(12) << mx << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}