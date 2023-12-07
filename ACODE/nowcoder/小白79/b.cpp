#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;

    for (int i = 0; i < q; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	--l, --r;
    	std::string t;
    	for (int j = l; j <= r; ++j) t = t + s[j] + s[j];
    	s = s.substr(0, l) + t + s.substr(r);
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}