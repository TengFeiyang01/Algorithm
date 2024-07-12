#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    bool ok = true;
    // 考虑若初始的前k个相同 那么s[0:k]->s[1:k+1] 增加了s[0]减少了s[0+k] 显然s[0]==s[0+k]
    // 显然每间隔k个位置都应该是相同的

    for (int i = k; i < n; ++i) {
    	if (s[i] == '?' || s[i] == s[i % k]) {
    		continue;
    	}
    	if (s[i % k] == '?') {
    		s[i % k] = s[i];
    	} else {
    		ok = false;
    		break;
    	}
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; ++i) {
    	if(s[i] == '0') {
    		cnt0++;
    	} else if (s[i] == '1') {
    		cnt1++;
    	}
    }
    if (cnt0 * 2 > k or cnt1 * 2 > k) {
    	ok = false;
    }
    if (ok) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
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
