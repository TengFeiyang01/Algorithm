#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int k;
    std::cin >> s >> k;
    std::string ans;
    int j = 0;
    for (int i = 0; i <= k; ++i) {
        if (s[i] > '0' and s[i] < s[j]) {
            j = i;
        }
    }

    k -= j; //j左侧的都删除

    ans = s[j];
    for (int i = j + 1; i < s.size(); ++i) {
        while (ans.size() > 1 and ans.back() > s[i] and k) {
            ans.pop_back();
            k--;
        }
        ans += s[i];
    }
    while (k--) {
        ans.pop_back();
    }

    std::cout << ans << "\n";
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
