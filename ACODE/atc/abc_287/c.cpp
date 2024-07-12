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
const int N = 2e5 + 13;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

std::vector<int> g[N];

void solve() {
	int n, m;
	std::cin >> n >> m;
	DSU dsu(n);
	std::vector<int> idg(n, 0);

	if (n != m + 1) {
		std::cout << "No\n";
		return;
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		idg[a]++;
		idg[b]++;
		dsu.merge(a, b);
	}

	for (int i = 0; i < n; ++i) {
		if (idg[i] > 2 || !dsu.same(i, 0)) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
}	


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
