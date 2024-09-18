#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> s(n + 1);
    i64 tot = 0;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> s[i];
    	s[i] += s[i - 1];
    }

    tot = s[n];
    i64 res = 1e16;
    for (int i = 1; i <= n - 2; ++i) {
    	i64 s1 = s[i];
    	int l = i + 1, r = n - 1;
    	while (l < r) {
    		int mid = l + r + 1 >> 1;
    		if (s[n] - s[mid] >= s[mid] - s[i]) {
    			l = mid;
    		} else {
    			r = mid - 1;
    		}
    	}
    	i64 s2 = s[n] - s[l], s3 = s[l] - s[i];
    	res = std::min(res, std::max({s1, s2, s3}) - std::min({s1, s2, s3}));
    	if (l + 1 < n) {
    		s2 = s[n] - s[l + 1];
    		s3 = s[l + 1] - s[i];
    		res = std::min(res, std::max({s1, s2, s3}) - std::min({s1, s2, s3}));
    	}
    }	
    std::cout << res << "\n";
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
