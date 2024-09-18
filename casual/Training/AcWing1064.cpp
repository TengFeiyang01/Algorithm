#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 13, K = 120, M = 1 << 10;

//f[i][j][a] 表示当前已经放在 i 行，放置了 j 个国王， 且当前这一行放置的状态是 a 的方案数目
//显然 f[i][j][a] += f[i - 1][j - cnt[a]][b] 其中，b是所有能够转移到a的状态
ll f[N][K][M];
int n, m;
std::vector<int> head[M];
std::vector<int> state;
int cnt[M];

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < 1 << n; ++i) 
    	if (!(i & i >> 1)) {
    		state.eb(i);
    		cnt[i] = __builtin_popcount(i);
    	}
    for (int a : state)
        for (int b : state) 
            if (!(a & b) && !((a | b) & (a | b) >> 1))
                head[a].eb(b);
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; ++i)
        for (int j = 0; j <= m; ++j)
            for (int a : state)
                for (int b : head[a]) {
                    int c = cnt[a];
                    if (j >= c) 
                        f[i][j][a] += f[i - 1][j - c][b];
                }
    std::cout << f[n + 1][m][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
