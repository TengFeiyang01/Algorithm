#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

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
    int n, a, b;
    std::cin >> n >> a >> b;
    --a, --b;
    std::vector<std::vector<int>> adj(n);

    DSU uf(n);

    std::vector<bool> cycle(n, false);
    std::stack<int> st;

    bool ok = 1;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int ne) {
    	if (!ok) return;
    	if (u == ne) {
    		while (!st.empty()) {
    			cycle[st.top()] = 1;
    			st.pop();
    		}
    		ok = 0;
    		return;
    	}
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			if (!ok) return;
    			st.push(v);
    			dfs(v, u, ne);
    			if (!ok) return;
    			st.pop();
    		}
    	}
    };

    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	if (!uf.same(x, y)) uf.merge(x, y);
    	else {
    		st.push(x);
    		dfs(x, -1, y);
   	 	}
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    if (a == b) {
    	std::cout << "NO\n";
    	return;
    }
    if (cycle[b]) {
    	std::cout << "YES\n";
    	return;
    }

    int start = -1;
    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
    	if (cycle[u]) {
    		start = u;
    		return;
    	}
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		dfs1(v, u);
    	}
    };

    dfs1(b, -1);

    std::vector<int> dist(n, -1);
    std::queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (q.size()) {
    	int u = q.front();
    	q.pop();
    	for (auto v : adj[u]) {
    		if (dist[v] == -1) {
    			q.push(v);
    			dist[v] = dist[u] + 1;
    		}
    	}
    }
    if (dist[a] <= dist[b]) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n";
    }
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