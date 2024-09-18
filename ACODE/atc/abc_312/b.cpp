#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::vector<std::string> s{
		"###.?????",
		"###.?????",
		"###.?????",
		"....?????",
		"?????????",
		"?????....",
		"?????.###",
		"?????.###",
		"?????.###"
	};

	int n, m;
	std::cin >> n >> m;
    std::string a[n];
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::set<PII> ans;
    for (int i = 0; i < n - 8; ++i) {
    	for (int j = 0; j < m - 8; ++j) {
    		bool ok = 1;
    		for (int p = 0; p < 4; ++p) {
    			if (a[i + p].substr(j, 4) != s[p].substr(0, 4)) {
    				ok = 0;
    			}
    		}
    		for (int p = 5; p < 9; ++p) {
    			if (a[i + p].substr(j + 5, 4) != s[p].substr(5)) {
    				ok = 0;
    			}
    		}

    		if (ok) {
    			ans.insert({i + 1, j + 1});
    		}
    	}
    }
    for (auto [x, y] : ans) {
    	std::cout << x << " " << y << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
