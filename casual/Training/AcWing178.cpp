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
const int N = 1e4 + 13;
using arr = std::array<int, 3>;
std::vector<PII> g[N], rg[N];
int n, m, S, T, K;
std::vector<int> dist(N, inf), cnt(N);
std::vector<bool> st(N, 0);

void dijkstra() {
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;
    pq.emplace(0, T);
    dist[T] = 0;

    while (pq.size()) {
        auto[d, u] = pq.top(); pq.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto[v, w] : rg[u]) 
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
    }
}

int astar() {
    std::priority_queue<arr, std::vector<arr>, std::greater<arr>> pq;
    pq.push({dist[S], 0, S});

    while (pq.size()) {
        auto[_, d, u] = pq.top(); pq.pop();

        cnt[u]++;
        if (cnt[T] == K) return d;

        for (auto[v, w] : g[u]) {
            if (cnt[v] < K)
                pq.push({d + w + dist[v], d + w, v});
        }
    }
    return -1;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        rg[u].emplace_back(u, w);
    }
    std::cin >> S >> T >> K;

    dijkstra();
    K += (S == T);

    std::cout << astar();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
