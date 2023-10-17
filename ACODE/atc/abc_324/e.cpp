#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string t;
    std::cin >> n >> t;

    int m = t.size();
    std::vector<int> a(m + 1), b(m + 1);
    for (int i = 0; i < n; ++i) {
    	int x = 0, j = 0;
    	std::string s;
    	std::cin >> s;
    	for (auto c : s) {
    		if (j < m and t[j] == c) {
    			j++;
    		}
    	}
    	a[j]++;
    	j = m - 1;
    	std::reverse(s.begin(), s.end());
    	for (auto c : s) {
    		if (j >= 0 and c == t[j]) {
    			x++;
                j--;
    		}
    	}
    	b[x]++;
    }
    for (int i = m - 1; i >= 0; --i) {
    	b[i] += b[i + 1];
    }
    i64 ans = 0;
    for (int i = 0; i <= m; ++i) {
    	ans += 1LL * a[i] * b[m - i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}