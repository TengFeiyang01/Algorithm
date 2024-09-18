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
int n, m;

int head[N], idx;
struct e{
    int to, next;
}edge[N];

int d[N]{0};

//树的直径

void dfs(int u, int fa, int dep) {
	d[u] = dep;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		int to = edge[i].to;
		if (to == fa) continue;
		dfs(to, u, dep + 1);
	}
}

void add(int u, int v) {
    edge[idx].to = v;
    edge[idx].next = head[u];
    head[u] = idx++;
}


void solve() {
	std::cin >> n >> m;
	memset(head, -1, sizeof head);
	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1, -1, 0);
	int u = 0, cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] > cur) {
			cur = d[i];
			u = i;
		}
	}
	int ans = 0;
	dfs(u, -1, 0);
	for (int i = 1; i <= n; ++i) {
		ans = std::max(ans, d[i]);
	}
	std::cout << ans;

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
