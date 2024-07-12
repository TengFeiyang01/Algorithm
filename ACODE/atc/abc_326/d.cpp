#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::string R, C;
    std::cin >> N >> R >> C;
    
    int tot = 0;
    std::vector<int> row(N), col(N);
    std::vector ans(N, std::string(N, '.'));
    auto dfs = [&](auto self, int x, int y) {
        if (x == N) {
            if (tot == 3 * N) {
                std::cout << "Yes\n";
                for (int i = 0; i < N; i++) {
                    std::cout << ans[i] << "\n";
                }
                std::exit(0);
            }
            return;
        }
        if (y == N) {
            return self(self, x + 1, 0);
        }
        self(self, x, y + 1);
        for (int i = 0; i < 3; i++) {
            if (row[x] == 0 && i + 'A' != R[x]) {
                continue;
            }
            if (col[y] == 0 && i + 'A' != C[y]) {
                continue;
            }
            if (row[x] >> i & 1) {
                continue;
            }
            if (col[y] >> i & 1) {
                continue;
            }
            ans[x][y] = 'A' + i;
            row[x] ^= 1 << i;
            col[y] ^= 1 << i;
            tot += 1;
            self(self, x, y + 1);
            ans[x][y] = '.';
            row[x] ^= 1 << i;
            col[y] ^= 1 << i;
            tot -= 1;
        }
    };
    dfs(dfs, 0, 0);
    
    std::cout << "No\n";
    
    return 0;
}