#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> pos[2];
    std::vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        int newpos = pos[0].size() + pos[1].size() + 1;
        if (s[i] == '0') {
            if (pos[1].empty()) {
                pos[0].push_back(newpos);
            } else {
                newpos = pos[1].back();
                pos[1].pop_back();
                pos[0].push_back(newpos);
            }
        } else {
            if (pos[0].empty()) {
                pos[1].push_back(newpos);
            } else {
                newpos = pos[0].back();
                pos[0].pop_back();
                pos[1].push_back(newpos);
            }
        }
        ans[i] = newpos;
    }
  
    std::cout << pos[0].size() + pos[1].size() << "\n";
    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
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