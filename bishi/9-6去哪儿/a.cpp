#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 m, n;
    std::cin >> n >> m;
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    bool ok = false;
    auto check = [&](int x) {
    	auto c = b;
    	auto d = a;

    	std::sort(c.begin(), c.begin() + x);
    	std::sort(d.begin(), d.begin() + x);
    	i64 cur = 0;
    	
    	for (int i = 0; i < x; ++i) {
    		cur += c[i] * d[i];
    	}
    	if (cur >= m) {
    		ok = true;
    	}
    	return cur >= m;
    };

    int l = 0, r = n;
    while (l < r) {
    	int mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    if (!ok) {
    	l = -1;
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
