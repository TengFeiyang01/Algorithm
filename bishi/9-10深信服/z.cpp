#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
	    int ans = 0;
	    std::string s;
	    std::cin >> s;
	    std::map<char, std::vector<int>> pos;
	    std::map<char, int> cnt;
	    for (int i = 0; i < s.size(); ++i) {
	    	if (pos.count(s[i]) and pos[s[i]].back() + 1 != i) {
	    		cnt[s[i]]++;
	    	}
	    	pos[s[i]].push_back(i);
	    }
	    if (pos.size() == 1 or cnt.size() == 0) {
	    	std::cout << 1 << "\n";
	    	continue;
	    }

	    for (auto [k, v] : cnt) {
	    	if (v >= n) {
	    		ans++;
	    	}
	    }
	    std::cout << std::max(1, ans) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
