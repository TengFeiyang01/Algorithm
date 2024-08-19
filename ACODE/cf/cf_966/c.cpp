#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    std::string s;
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        pos[a[i]].push_back(i);
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
    	std::cin >> s;
    	bool ok = true;
        std::map<int, std::vector<int>> pos1;
        if (s.size() != n) {
            ok = false;
        } else {
            for (int j = 0; j < s.size(); ++j) {
                pos1[s[j]].push_back(j);
            }
            for (auto [_, v] : pos) {
                for (auto p : v) {
                    if (s[p] != s[v[0]]) {
                        ok = false;
                    }
                } 
            }
            for (auto [_, v] : pos1) {
                for (auto p : v) {
                    if (a[p] != a[v[0]]) {
                        ok = false;
                    }
                }
            }
        }

        
    	std::cout << (ok ? "YES\n" : "NO\n");
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
