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
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> s(n + 1);
    std::vector<int> len(n + 1);

    std::vector<std::vector<int>> dp(101, std::vector<int>(101, inf));

    auto get = [&](int x, int y) {
    	
        for (int i = 0; i <= len[x]; ++i) {
            for (int j = 0; j <= len[y]; ++j) {
                dp[i][j] = 0;
            }
        }

    	for (int i = 1; i <= len[x]; ++i) {
    		for (int j = 1; j <= len[y]; ++j) {
    			if (s[x][i - 1] == s[y][j - 1]) {
    				dp[i][j] = dp[i - 1][j - 1] + 1;
    			} else {
    				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    			}
    		}
    	}
    	return len[x] + len[y] + k - 2 * dp[len[x]][len[y]];
    };

    std::vector<std::array<int, 3>> edges;

    for (int i = 1; i <= n; ++i) {
    	std::cin >> len[i] >> s[i];
    	edges.push_back({len[i], 0, i});
    }

    for (int i = 1; i <= n; ++i) {
    	for (int j = i + 1; j <= n; ++j) {
    		edges.push_back({get(i, j), i, j});
            continue;
    	}
    }

    std::sort(edges.begin(), edges.end());

    DSU uf(n + 1);

    int ans = 0;
    for (auto e : edges) {
    	int u = e[2], v = e[1], w = e[0];
    	if (!uf.same(u, v)) {
    		uf.merge(u, v);
    		ans += w;
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
