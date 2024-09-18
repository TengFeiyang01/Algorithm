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
const int N = 1e5 + 13;
int cnt = 0;

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
        if (x == y) {
        	cnt++;
        	return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
	int x, y;
	DSU dj(n + 1);
	std::set<int> st;
	while (m--) {
		std::vector<int> v;
		int x, y;
		std::cin >> x >> y;
		dj.merge(x, y);
		for (int j = 1; j <= n; ++j) {
			if (dj.leader(j) == j) {
				v.eb(dj.size(j));
			}
		}
		std::sort(all(v), std::greater<int>());
		int ans = 0;
		for (int j = 0; j < sz(v) && j <= cnt; ++j) {
			ans += v[j];
		}
		ans--;
		std::cout << ans << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
