#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int c = std::count(s.begin(), s.end(), '(');
    if (2 * c != n) {
        std::cout << -1 << "\n";
        return;
    }
    
    std::vector<int> ans(n, 2);
    
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            a.push_back(i);
        } else if (!a.empty()) {
            ans[i] = 1;
            ans[a.back()] = 1;
            a.pop_back();
        }
    }
    
    if (std::count(ans.begin(), ans.end(), 2)) {
        a.clear();
        ans.assign(n, 2);
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                a.push_back(i);
            } else if (!a.empty()) {
                ans[i] = 1;
                ans[a.back()] = 1;
                a.pop_back();
            }
        }
    }
    
    std::cout << *std::max_element(ans.begin(), ans.end()) << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}