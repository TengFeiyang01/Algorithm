#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int cnt = 1;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    int j = 0;
    for (auto c : t) {
        if (c == s[j]) j += 1;
    }

    std::cout << "Case #" << cnt++ << ": ";

    if (j == n) {
    	std::cout << m - n << "\n";
    } else {
    	std::cout << "IMPOSSIBLE\n";
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
