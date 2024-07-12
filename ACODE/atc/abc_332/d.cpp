#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    std::vector b(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> b[i][j];
    	}
    }

    int ans = inf;
    std::vector<int> row(n);
    std::iota(row.begin(), row.end(), 0);
    do {
        std::vector<int> col(m);
        std::iota(col.begin(), col.end(), 0);
        do {    
            bool match = true;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    match &= (a[row[i]][col[j]] == b[i][j]);
                }
            }
            if (match) {
                int inv = 0;
                for (int i = 0; i < n; ++i) {
                    for (int j = i + 1; j < n; ++j) {
                        inv += (row[i] > row[j]);
                    }
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = i + 1; j < m; ++j) {
                        inv += (col[i] > col[j]);
                    }
                } 
                ans = std::min(ans, inv);
            }
        } while (std::next_permutation(col.begin(), col.end()));
    } while (std::next_permutation(row.begin(), row.end()));
    if (ans == inf) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
