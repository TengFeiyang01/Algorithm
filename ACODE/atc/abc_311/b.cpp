#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, d, ans = 0;
    std::cin >> n >> d;

    std::vector<int> a(d);
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	for (int j = 0; j < d; ++j) {
    		if (s[j] == 'x') {
    			a[j] = 1;
    		}
    	}
    }

    for (int i = 0, cnt = 0; i < d; ++i) {
    	if (a[i] == 0) {
    		cnt++;
    	} else {
    		cnt = 0;
    	}
        ans = std::max(ans, cnt);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
