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
const int N = 1e3 + 13;

int n, m, v[N], w[N], a[N], f[N];
std::vector<int> c[N];

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> v[i] >> w[i];
        c[a[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 0; --j) {
            for (auto k : c[i])
                if (v[k] <= j)
                    f[j] = std::max(f[j], f[j - v[k]] + w[k]);
        }
    std::cout << f[m];

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}