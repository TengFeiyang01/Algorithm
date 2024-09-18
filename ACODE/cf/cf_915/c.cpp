#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> stk;
    for (int i = 0; auto c : s) {
        while (!stk.empty() and s[stk.back()] < c) {
            stk.pop_back();
        }
        stk.push_back(i++);
    }
    int ans = stk.size() - 1;

    std::string t = "";
    t += s[stk[0]];
    for (int i = 1; i < stk.size(); ++i) {
        if (s[stk[i]] == s[stk[0]]) {
            ans--;
        }
        t += s[stk[i]];
    }
    std::ranges::sort(t);
    for (int i = 0; auto p : stk) {
        s[p] = t[i++];
    }
    if (std::ranges::is_sorted(s)) {
        std::cout << ans << "\n";
    } else {
        std::cout << "-1\n";
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
