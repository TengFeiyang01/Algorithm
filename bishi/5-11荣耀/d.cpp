#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string ans;
    for (int i = 0; i < n; ++i) {
    	if (isdigit(s[i])) {
    		int j = i;
    		i64 cnt = 0;
    		while (j < n and isdigit(s[j])) {
    			cnt = cnt * 10LL + (s[j] - '0');
    			j++;
    		}
    		if (cnt) {
    			ans += std::string(cnt, s[j]);
    		}
    		i = j;
    	} else {
    		ans += s[i];
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
