#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int x, y, n = s.size();
    std::cin >> x >> y;
    std::vector<bool> l(n), r(n);
    for (int i = 0, p = 0; i < n; ++i) {
    	int d = s[i] - '0';
    	p = p * 10 + d;
    	if (p % x == 0) {
    		l[i] = true;
    	}
    	p %= x;
    }

    for (int i = n - 1, p = 0, q = 1; i >= 0; --i) {
    	int d = s[i] - '0';
    	if (d * q % y == 0) {
    		r[i] = true;
    	}
    	q = q * 10 % y;
    }
    for (int i = 1; i < n; ++i) {
    	if (s[i] != '0' and l[i - 1] and r[i]) {
    		std::cout << s.substr(0, i) << " " << s.substr(i) << "\n";
    		return;
    	}
    }
    std::cout << "-1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
