#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
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
using vector = std::vector<std::vector<PII>>;
const int N = 2e5 + 13;
int a[N];
ll f1[N], f2[N], up[N];
int son[N];

vector g;

void dfs1(int u, int fa) {
	f1[u] = a[u];
	son[u] = u;
	for (auto[v, w] : g[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		if (f1[v] + w > f1[u]) {
			f2[u] = f1[u];
			f1[u] = f1[v] + w;
			son[u] = v;
		} else if (f1[v] + w > f2[u]) {
			f2[u] = f1[v] + w;
		}
	}
}

void dfs2(int u, int fa) {
	for (auto[v, w] : g[u]) {
		if (v == fa) continue;
		if (v == son[u]) {
			up[v] = std::max(up[v], std::max(f2[u] + w, up[u] + w));
		} else {
			up[v] = std::max(up[v], std::max(f1[u] + w, up[u] + w));
		}
		dfs2(v, u);
	}
}

void solve() {
    int n;
    std::cin >> n;
    g.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
    	int a, b, c;
    	std::cin >> a >> b >> c;
    	g[a].eb(b, c);
    	g[b].eb(a, c);
    }
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
    	if (son[i] == i) std::cout << std::max(f2[i], up[i]) << "\n";
    	else std::cout << std::max(f1[i], up[i]) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
