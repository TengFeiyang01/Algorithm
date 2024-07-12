#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int i = 0;
    while (i < s.size() and s[i] == t[i]) i++;
    std::cout << i + 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
