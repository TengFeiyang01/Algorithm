#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, i64>;
const int N = 1e5 + 13;


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        std::cin >> a >> b >> d;
        a--, b--;
        g[a].emplace_back(b, -d);
        g[b].emplace_back(a, d);
    }
    
    std::vector<i64> f(n);
    std::vector<bool> st(n);

    for (int i = 0; i < n; ++i) {
        if (!st[i]) {
            st[i] = 1;
            std::queue<int> q;
            q.push(i);

            while (q.size()) {
                int x = q.front();
                q.pop();

                for (auto[y, d] : g[x]) {
                    if (!st[y]) {
                        st[y] = 1;
                        q.push(y);
                        f[y] = f[x] + d;
                    } else if (f[y] != f[x] + d) {
                        std::cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
