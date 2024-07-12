#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;


  int maximalRectangle(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        vector<vector<int>> s(m + 1, vector<int>(n + 1,  0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > 0) {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
               	s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + matrix[i][j]; 
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                int x1 = up[i] + 1, x2 = down[i] - 1;
                int y1 = j - left[i][j] + 1, y2 = j;

                std::cout << x1 << " " << y1 << "  " << x2 << " " << y2 << "\n";
                x1++, x2++, y1++, y2++;
                ret = std::max(ret, s[x2][y2] + s[x1 - 1][y1 - 1] - s[x1 - 1][y2] - s[x2][y1 - 1]);
            }
        }
        return ret;
    }

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    std::vector s(n + 1, std::vector(m + 1, 0));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    std::cout <<     maximalRectangle(a);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
