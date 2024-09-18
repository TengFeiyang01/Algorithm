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
const int N = 13;

std::set<int> st;
int n, m, k;
const int dirs[] = {-1, 0, 1, 0, -1};

int g[N][N];
std::string s = "";
void dfs(int x, int y, int t, int cur) {
	if (t == k + 1) {
		st.insert(cur);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dirs[i], ny = y + dirs[i + 1];
		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		dfs(nx, ny, t + 1, cur * 10 + g[nx][ny]);
	}
}

void solve() {
    std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> g[i][j];
	int ans = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			dfs(i, j, 1, g[i][j]);
		} 
	std::cout << sz(st) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
