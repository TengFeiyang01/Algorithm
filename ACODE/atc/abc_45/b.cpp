#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s[3];
    std::cin >> s[0] >> s[1] >> s[2];
    std::map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 1;
    mp['c'] = 2;
    int now = 0;
    std::ranges::reverse(s[0]);
    std::ranges::reverse(s[1]);
    std::ranges::reverse(s[2]);
    while (s[now].size()) {
        int temp = now;
        now = mp[s[now].back()];
        s[temp].pop_back();
    }
    std::string ans = "ABC";
    std::cout << ans[now];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
