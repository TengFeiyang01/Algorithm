#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = t.size();	
    std::vector<int> z(n);
    i64 ans = 0;
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
    	if (i <= r) z[i] = std::min(z[i - l], r - i + 1);
    	while (t[z[i]] == t[i + z[i]]) z[i]++;
    	if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }

    for (i64 i = 0LL; auto x : z) {
    	ans ^= (i + 1) * (x + 1);
        i++;
    }

    int m = s.size();
    std::vector<int> p(m);
    for (int i = 0, l = 0, r = -1; i < m; ++i) {
    	if (i <= r) p[i] = std::min(z[i - l], r - i + 1);
    	while (p[i] < n and i + p[i] < m and t[p[i]] == s[i + p[i]]) p[i]++;
    	if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
    }
    i64 res = 0;
    for (i64 i = 0LL; auto x : p) {
    	res ^= (i + 1) * (x + 1);
        i++;
    }
    std::cout << ans << "\n" << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
