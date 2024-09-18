#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 2e5 + 13;

std::array<int, 3> E[N];
std::array<int, 2> Q[N];
std::vector<int> vec[N];
std::vector<std::pair<int, int>> que[N];
int f[N], ans[N], belong[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i < n; ++i) {
    	std::cin >> E[i][1] >> E[i][2] >> E[i][0];
    }
    std::sort(E + 1, E + n);
    std::reverse(E + 1, E + n);
    for (int i = 1; i <= n; ++i) {
        vec[i].push_back(i);
        belong[i] = i;
        f[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        std::cin >> Q[i][0] >> Q[i][1];
        que[Q[i][0]].emplace_back(i, Q[i][1]);
        que[Q[i][1]].emplace_back(i, Q[i][0]);
    }
    
    for (int i = 1; i < n; ++i) {
        int u = find(E[i][1]), v = find(E[i][2]);
        if (vec[u].size() > vec[v].size()) {
            std::swap(u, v);
        }
        for (auto [id, w] : que[u]) {
            if (ans[id] != 0) continue;
            if (belong[w] == v) {
                ans[id] = E[i][0];
            } else {
                que[v].emplace_back(id, w);
            }
        }
        que[u].clear();
        for (auto w : vec[u]) {
            vec[v].push_back(w);
            belong[w] = v;
        }
        vec[u].clear();
        f[u] = v;
    }
    for (int i = 1; i <= m; ++i) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}