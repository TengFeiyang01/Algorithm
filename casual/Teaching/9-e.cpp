#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector grid(n, std::vector(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
        }
    }

    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    --x1, --x2, --y1, --y2;

    int t;
    std::cin >> t;
    std::vector<int> col(t);
    for (int i = 0; i < t; ++i) {
        std::cin >> col[i];
        col[i]--;
    }

    // 根据列进行稳定排序
    std::vector<int> slice(x2 - x1 + 1);  // [l, r] r-1+1
    for (int i = x1; i <= x2; ++i) {
        // 3 4 5

        // 0 1 2
        // 3 4 5
        slice[i - x1] = i;
    }

    std::sort(slice.begin(), slice.end(), [&](int i1, int i2) -> bool {
        std::vector<int> x, y;
        for (auto j : col) {
            x.push_back(grid[i1][j + y1]);
            y.push_back(grid[i2][j + y1]);
        }
        return x < y;

        // for (auto j : col) {
        //     if (grid[i1][j + y1] != grid[i2][j + y1]) {
        //         return grid[i1][j + y1] < grid[i2][j + y1];
        //     }
        // }
        // return false;
    });


    std::vector<std::vector<int>> sub(x2 - x1 + 1);
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            sub[i - x1].emplace_back(grid[i][j]);
        }
    }
    
    for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
            grid[i][j] = sub[slice[i - x1] - x1][j - y1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << grid[i][j] << " \n"[j == m - 1];
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}

/*

3 7 5

1 6 7
3 5 6

1 6 7
3 7 5
3 5 6

1 6 7
3 5 6
3 7 5
*/
