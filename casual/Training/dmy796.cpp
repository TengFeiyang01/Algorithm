#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

unsigned int A, B, C;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}

int main(){
	int n, m, tot = 0;
    scanf("%d%d%u%u%u", &n, &m, &A, &B, &C);
    // 输入树边
    std::vector<int> dfn(n * 3), dep(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<std::vector<std::pair<int, int>>> f(22, std::vector<std::pair<int, int>>(n * 3));
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	dfn[u] = ++tot;
    	dep[u] = dep[fa] + 1;
    	f[0][tot] = {dep[u], u};

    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			f[0][++tot] = {dep[u], u};
    		}
    	}
    };
    dfs(1, 0);

    for (int j = 1; j <= 20; ++j) {
    	for (int i = 1; i + (1 << j) - 1 <= tot; ++i) {
    		f[j][i] = std::min(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
    	}
    }
    i64 ans = 0;
    for (int i = 1; i <= m; i++) {
        unsigned int l = dfn[rng61() % n + 1], r = dfn[rng61() % n + 1];
    	if (l > r) std::swap(l, r);
    	int len = std::__lg(r - l + 1);
    	int d = std::min(f[len][l], f[len][r - (1 << len) + 1]).second;
    	ans ^= 1LL * i * d;
    }
    printf("%lld\n", ans);
}
