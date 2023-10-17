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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::vector<ll> a(n);
    
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    vector g(n, std::vector<int>(n, inf));
    vector f(n, std::vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {	
		std::cin >> s;
		for (int j = 0; j < n; ++j) {
			if (s[j] == 'Y') {
				g[i][j] = 1;
				st[i][j] = 1;
				f[i][j] = a[j];
			}
			if (i == j) {
				g[i][j] = 0;
			}
		}
	}

	//不算起点， 最终加上？

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
					f[i][j] = f[i][k] + f[k][j];
				} else if (g[i][j] == g[i][k] + g[k][j]) {
					f[i][j] = std::max(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}

	auto find = [&](int k, int u, int v)->int {

	};


	int m;
	std::cin >> m;
	while (m--) {
		int u, v;
		std::cin >> u >> v;
		u -= 1;
		v -= 1;
		if (g[u][v] == inf) {
			std::cout << "Impossible\n";
		} else {
			int t = g[u][v];
			std::cout << g[u][v] << " " << a[u] + f[u][v] << "\n";
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
