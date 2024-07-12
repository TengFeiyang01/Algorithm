#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
	
	i64 ans = 0, l = 0, r = 0;
	
	for (r = 0; r < n; ++r) {
		if (r and s[r] == 'x' and s[r - 1] == 'x') {
			l = r;
		}
		if (r > 1 and s[r] == 'o' and s[r - 1] == 'o' and s[r - 2] == 'o') {
			l = r - 1;
		}
		if (r > 1 and s[r] == 'x' and s[r - 1] == 'o' and s[r - 2] == 'x') {
			l = r - 1;
		}
		ans += r - l + 1;
	}  

	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
