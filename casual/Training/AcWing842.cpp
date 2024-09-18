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

int n, st[N], p[N];

void dfs(int u) {
	if (u == n + 1) {
		for (int i = 1; i <= n; ++i)
			std::cout << p[i] << " \n"[i == n];
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!st[i]) {
			p[u] = i;
			st[i] = 1;
			dfs(u + 1);
			st[i] = 0;
		}
	}

}

void solve() {
	std::cin >> n;
	dfs(1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
