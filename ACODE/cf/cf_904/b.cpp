#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int n;
    std::cin >> n >> s;
    i64 ans = 0, cnt = 0;
    std::reverse(s.begin(), s.end());
    std::set<int> pos;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '0') {
    		pos.insert(i);
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 0) {
    		ans += cnt;
    		std::cout << ans << " ";
    	} else {
			if (pos.size()) {
		    	int j = *pos.begin();
	    		ans += j - i;
	    		cnt += 1;
	    		std::cout << ans << " ";
                pos.erase(pos.begin());
            } else {
    			std::cout << "-1 ";
    		}
    	}
    }
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}