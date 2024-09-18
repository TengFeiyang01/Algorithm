#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

bool check(std::string a, std::string b) {
    int m = b.size();
    int i = 0;
    for (auto c : a) {
        if (c == b[i]) {
            i++;
            if (i == m) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> t;
    int y = t.size();
    std::vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s;
        int x = s.size();

        if (abs(x - y) > 1) continue;

        if (x > y and check(s, t)) {
            ans.push_back(i);
            continue;
        }
        
        if (y > x and check(t, s)) {
            ans.push_back(i);
            continue;
        }
        if (x != y) continue;
        int cnt = 0;
        for (int i = 0; i < x; ++i) {
            cnt += (s[i] != t[i]);
        }
        if (cnt <= 1) {
            ans.push_back(i);
        }
    }
    int m = ans.size();
    std::cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << " \n"[i == m - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}