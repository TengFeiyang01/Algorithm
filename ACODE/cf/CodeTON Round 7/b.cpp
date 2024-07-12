#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int i = 0, j = n - 1;
    while (j >= 0 and s[j] == 'A') --j;
    while (i < n and s[i] == 'B') ++i;
    std::cout << std::max(j - i, 0) << "\n";
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
