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
const int N = 1e6 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> f(m + 1), q(m + 1);
    //int g[N], f[N], q[N];
    for (int i = 0; i < n; ++i) {
        int v, w, s;
        std::cin >> v >> w >> s;
        auto g = f;
        //memcpy(g, f, sizeof f);
        for (int j = 0; j < v; ++j) {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v) {
                //队头出队
                while (hh <= tt && k - s * v > q[hh]) hh++;
                //队头更新答案
                if (hh <= tt) f[k] = std::max(g[k], g[q[hh]] + (k - q[hh]) / v * w);
                //维持队列单调性 
                while (hh <= tt && g[k] >= g[q[tt]] + (k - q[tt]) / v * w) tt--;
                q[++tt] = k;
            }
        }
    }
    std::cout << f[m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
