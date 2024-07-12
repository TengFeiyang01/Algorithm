#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    	if (b[i] == a[i]) {
    		s[i] = 1;
    	}
    	s[i] += s[i - 1];
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	if (s[r] - s[l - 1]) {
    		std::cout << "NO\n";
    	} else {
    		std::cout << "YES\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	solve();

    return 0;
}
