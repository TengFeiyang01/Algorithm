#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < n and s[l] == '0') l++;
    while (r >= 0 and s[r] == '0') r--;
    int u = 1, d = 1;
    for (int i = r - 1; i >= l; --i) {
        if (s[i] == '1')
            u = std::min(u, d) + 1;
        else
            d = std::min(d, u) + 1;
    }
    std::cout << 2 * u - 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
