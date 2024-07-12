#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x;
    std::cin >> x;
    if (x <= 2) {
    	std::cout << x << "\n";
    }
    double mx = 0;
    int t = 0, p = 0, q = 0;
    for (int i = 2; i <= x; ++i) {
    	double cur = 1;
    	for (int j = 0; j < i; ++j) {
    		cur = cur * double(x) / i;
    	}
    	if (cur > mx) {
    		mx = cur;
    		t = i;
    		p = x / std::__gcd(i, x);
    		q = i / std::__gcd(i, x);
    	}
    }
    int a = 1, b = 1;
    
    for (int j = 0; j < t; ++j) {
    	a *= p;
    	b *= q;
    }

    std::cout << a << " " << b;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
