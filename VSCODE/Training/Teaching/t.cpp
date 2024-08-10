#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = s + s;

    int i = 0, j = 1, k = 0;
    while (i < n and j < n) {
        for (k = 0; k < n and s[i + k] == s[j + k]; ++k)
        if (s[i + k] > s[j + k]) {
            i = i + k + 1;
        } else if (s[i + k] < s[j + k]) {
            j = j + k + 1;
        }
        if (i == j) {
            i++;
        }
    }
    int x = std::min(i, j);
    std::cout << x << " " << s.substr(x, n) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}