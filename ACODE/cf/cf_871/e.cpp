#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
const int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j) 
    		std::cin >> grid[i][j];
    int ans = 0;


    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j]) {
                int s = 0;
                std::queue<PII> q;
                q.emplace(i, j);
                s += grid[i][j];
                grid[i][j] = 0;
                while (q.size()) {
                    auto[x, y] = q.front();
                    q.pop();
                        
                    for (int k = 0; k < 4; ++k) {
                        int a = x + dirs[k], b = y + dirs[k + 1];
                        if (a < 0 || a >= n || b < 0 || b >= m || !grid[a][b]) continue;
                        s += grid[a][b];
                        grid[a][b] = 0;
                        q.emplace(a, b);
                    }
                }
                ans = std::max(ans, s);
            }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
