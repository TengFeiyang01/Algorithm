#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::vector<int> stk;
    int n = s.size(), x = 0;
    char pre = '$';
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i])) {
            x = x * 10 + (s[i] - '0');
        }
        if (!isdigit(s[i]) || i == n - 1) {
            if (pre == '$') {
                stk.push_back(x);
            } else {
                stk.back() = 2 * stk.back() + x + 3;
            }
            pre = s[i];
            x = 0;
        }
    }
    

    x = stk[0];
    for (int i = 1; i < stk.size(); ++i) {
        x = 3 * x + 2 * stk[i] + 1;
    }

    std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
