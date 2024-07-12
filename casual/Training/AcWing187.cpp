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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];
int ans = inf, up[N], down[N];

void dfs(int u, int su, int sd) {
	if (sd + su >= ans) return;
	if (u == n) {
		ans = su + sd;
		return;
	}
	//case1
	int k = 0;
	while (k < su && nums[u] <= up[k]) ++k;
	int t = up[k];
	up[k] = nums[u];
	if (k < su)	dfs(u + 1, su, sd);
	else dfs(u + 1, su + 1, sd);
	up[k] = t;

	k = 0;
	while (k < sd && nums[u] >= down[k]) ++k;
	t = down[k];
	down[k] = nums[u];
	if (k < sd) dfs(u + 1, su, sd);
	else dfs(u + 1, su, sd + 1);
	down[k] = t;	
}

void solve() {
    while (std::cin >> n, n) {
    	for (int i = 0; i < n; ++i) std::cin >> nums[i];
    	ans = inf;
    	dfs(0, 0, 0);
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
