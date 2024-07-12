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
const int N = 110, M = 1 << 10;

int n, m;
std::vector<int> head[M];
std::vector<int> state;
ll f[2][M][M]{0};
//f[i][a][b]
//前 i 行已经摆好，第 i 行状态是 a，第 i-1 行状态是 b 的集合
int g[N];
ll cnt[M];

void solve() {
    std::cin >> n >> m;
    std::vector<int> g(n + 2);
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j)
            g[i] += (s[j] == 'H') << j;
    }

    //枚举所有合法状态
    for (int i = 0; i < 1 << m; ++i) {
        if (!(i & i >> 1 || i & i >> 2)) {
            state.eb(i);
            cnt[i] = __builtin_popcount(i);
        }
    }

    for (int a : state)
        for (int b : state)
            if (!(a & b))
                head[a].eb(b);

    for (int i = 1; i <= n + 2; ++i)
        for (auto a : state)
            for (int b : head[a])
                for (int c : head[b]) {
                    if (g[i] & a || g[i - 1] & b) continue;
                    //if (a & b || b & c || a & c) continue;
                    if (a & c) continue; //a与b相互转移过来的时候，已经判断了 a & b 的情况
                    f[i & 1][a][b] = std::max(f[i & 1][a][b], f[i - 1 & 1][b][c] + cnt[a]);
                }

    std::cout << f[n + 2 & 1][0][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
