#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n - 1; ++i) {
    	if (s[i] == '0') continue;
    	int st = i;
    	for (; i < n - 1 and s[i] == '1'; ++i) {}
    	std::sort(a.begin() + st, a.begin() + i + 1);
    }
    if (std::ranges::is_sorted(a)) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
