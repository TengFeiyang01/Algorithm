#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

//任何长度大于3的字符串均可以分成长度为2和3的字段
//把n个字符串中长度为2和3的子段位置以及这些子段所在字符串的下标存起来

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<std::string, int> st;
    std::map<std::string, std::array<int, 3>> pos;
    std::vector<int> dp(m + 2), pre(m + 1);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m - 1; ++j) {
            if (j + 1 < m and !st.count(s.substr(j, 2))) {
                st[s.substr(j, 2)] = 1;
                pos[s.substr(j, 2)] = {j + 1, j + 2, i + 1};
            }
            if (j + 2 < m and !st.count(s.substr(j, 3))) {
                st[s.substr(j, 3)] = 1;
                pos[s.substr(j, 3)] = {j + 1, j + 3, i + 1};
            }          
        }
    }
    std::string s;
    std::cin >> s;
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        std::string t;
        t = s[i];
        for (int j = 1; j <= 2; ++j) {
            if (i - j < 0) break;
            t = s[i - j] + t;
            if (st[t] and dp[i - j]) {
                dp[i + 1] = 1;
                pre[i + 1] = i - j;
            }
            if (dp[i + 1]) break;
        }
    }
    if (!dp[m]) {
        std::cout << "-1\n";
        return;
    }
    std::vector<std::array<int, 3>> ans;
    for (int i = m; i > 0;) {
        int p = pre[i];
        std::string t = s.substr(p, i - p);
        ans.push_back(pos[t]);
        i = p;
    }
    std::cout << ans.size() << "\n";
    std::reverse(ans.begin(), ans.end());
    for (auto [l, r, id] : ans) {
        std::cout << l << " " << r << " " << id << "\n";
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
