#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
constexpr int N = 1e5 + 13;
constexpr int mod = 1e9 + 7; 

void solve() {
    std::string s;
    i64 c;
    std::cin >> s >> c;
    int n = s.size();
    std::vector<i64> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * (c + 1) % mod;

    i64 ans = 0, pre = 1;

    for (int i = 0; i < n; ++i) {
    	if (s[i] == '1') {
    		ans = (ans + pre * pw[n - i - 1]) % mod;
    		pre = pre * c % mod;
    	} 
    }
    ans = (ans + pre) % mod;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
