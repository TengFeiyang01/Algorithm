#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<PII> g[n];

    DSU uf(n);

    std::vector<int> neg(n, 0);

    for (int i = 0; i < m; ++i) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	g[x - 1].emplace_back(y - 1, z);
    	g[y - 1].emplace_back(x - 1, -z);
    	uf.merge(x - 1, y - 1);
    }

    std::vector<i64> dist(n, 1e15);

    //u, v 不在同一连通块 nan
    //u, v 所处的连通块有正权环 inf
    //判断正权环：选出一点进行 bfs 若到达某一点的距离不唯一 存在正权环 

    auto bfs = [&](int s) {
    	std::queue<int> q;
    	q.push(s);
    	dist[s] = 0;
    	while (q.size()) {
    		int u = q.front();
    		q.pop();
    		for (auto[v, w] : g[u]) {
    			if (dist[v] == 1e15) {
    				dist[v] = dist[u] + w;
    				q.push(v);
    			} else if (dist[v] != dist[u] + w) {
    				neg[s] = 1;
    			}
    		}
    	}
    };

    for (int i = 0; i < n; ++i) {
    	if (uf.find(i) == i) bfs(i);
    }
    while (q--) {
    	int u, v;
        std::cin >> u >> v;
        --u, --v;
        if (!uf.same(u, v)) {
            std::cout << "nan" << "\n";
        } else if (neg[uf.find(u)]) {
            std::cout << "inf" << "\n";
        } else {
            std::cout << dist[v] - dist[u] << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
