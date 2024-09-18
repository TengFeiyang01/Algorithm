#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    auto check = [&](int x) {
    	if (x < 2) return false;
    	for (int i = 2; i * i <= x; ++i) {
    		if (x % i == 0) {
    			return false;
    		}
    	}
    	return true;
    };
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    if (n == 1) {
    	std::cout << "-1\n";
    	return;
    } else if (n == 2) {
    	std::cout << "1\n";
    	return;
    } 

    int cnt = 0, x = 0;
    for (int i = 0; i < n - 1; ++i) {
    	if (!i) {
    		if (check(a[i] + a[i + 2]) and check(a[i] + a[i + 1])) {
    			cnt++;
    			x = i + 1;
    		}
    	} else {
    		if (i + 2 < n) {
    			if (check(a[i] + a[i + 2]) and check(a[i - 1] + a[i + 1]) and check(a[i] + a[i + 1])) {
    				cnt++;
    				x = i + 1;
    			}
    		} else {
    			if (check(a[i - 1] + a[i + 1]) and check(a[i] + a[i + 1])) {
    				cnt++;
    				x = i + 1;
    			}
    		}
    	}
    }

    if (cnt > 1 or cnt <= 0) {
    	std::cout << "-1\n";
    } else {
    	std::cout << x << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
