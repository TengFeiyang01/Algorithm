#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n;
    std::cin >> n;
    std::vector<int> s;
    while (n) {
        s.push_back((n % 9 >= 4) ? (n % 9 + 1) : n % 9);
        n /= 9;
    }
    std::reverse(s.begin(), s.end());
    for (int x : s) std::cout << x;
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
