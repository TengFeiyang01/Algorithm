#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, p;
    std::cin >> s >> p;
    int m = s.size(), n = p.size();
    s.insert(s.begin(), ' ');
    p.insert(p.begin(), ' ');
    std::vector<std::vector<bool>> f(m + 1, std::vector<bool>(n + 1, false));
    f[0][0] = true;
    //处理一下f[0][j]能匹配的情况 即x*
    for (int j = 1; j <= n; ++j) {
        if (p[j] == '*') f[0][j] = f[0][j - 1];
        else if (j + 1 > n or p[j + 1] != '*') break;
        else f[0][j] = true;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j + 1 <= n and p[j + 1] == '*') continue;
            if (p[j] != '*') f[i][j] = f[i - 1][j - 1] and (s[i] == p[j] or p[j] == '.');
            else if (p[j] == '*') {
                f[i][j] = (j >= 2) and f[i][j - 2] or f[i - 1][j] and (s[i] == p[j - 1] or p[j - 1] == '.');
            }
        }
    }
    if (f[m][n]) {
    	std::cout << "true";
    } else {
    	std::cout << "false";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
