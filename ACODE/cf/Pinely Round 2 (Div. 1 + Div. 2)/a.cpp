#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, q;
    std::string s;
    std::cin >> n >> m >> q >> s;
    
    int ok = (m == n);
    int sum = m, a = m;
    for (auto c : s) {
        a += (c == '+' ? 1 : -1);
        sum += (c == '+' ? 1 : 0);
        ok |= (a == n);
    }

    if (ok) {
    	std::cout << "YES\n";
    } else if (sum < n) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "MAYBE\n";
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