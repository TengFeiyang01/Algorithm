#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    std::vector<int> ans;
    std::vector<std::set<int>> col(m);
    for (int i = 0; i < n; ++i) {
        bool ok = true, f = false;
        for (int j = 0; j < m; ++j) {
            if (col[j].count(a[i][j])) {
                f = true;
                break;
            }
        }
        if (f) {
            ans.push_back(i + 1);
            for (int j = 0; j < m; ++j) {
                if (col[j].count(a[i][m - 1 - j])) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            std::cout << "No\n";
            return;
        }

        for (int j = 0; j < m; ++j) {
            if (!f) {
                col[j].insert(a[i][j]);
            } else {
                col[j].insert(a[i][m - 1 - j]);
            }
        }
    }
    std::cout << "Yes\n";
    std::cout << ans.size() << "\n";
    for (int x : ans) {
        std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
