#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> g[n], st(n);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
	    g[x - 1].push_back(y - 1);
	    g[y - 1].push_back(x - 1);
    }

    std::priority_queue<PII> pq;
    
    std::vector<int> dist(n);

    std::set<int> ans;
    for (int i = 0; i < k; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    
        dist[x - 1] = y + 1;
        pq.emplace(y + 1, x - 1);
    }

    while (pq.size()) {
        auto [q, p] = pq.top();
        pq.pop();
        for (int i : g[p]) {
            if (q - 1 > dist[i]) {
                dist[i] = q - 1;
                pq.emplace(dist[i], i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i]) ans.insert(i);
    }

    std::cout << ans.size() << "\n";
    for (int x : ans) std::cout << x + 1 << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
