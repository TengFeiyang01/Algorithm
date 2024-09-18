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
const int N = 14, M = 1 << 12, K = 150;

int n, m;
std::vector<int> head[M];
std::vector<int> state;
ll f[N][M]{0};
const int mod = 1e8;

void solve() {
    std::cin >> n >> m;
    std::vector<int> g(n + 2);
    for (int i = 1; i <= n; ++i) 
    	for (int j = 0; j < m; ++j) {
    		int t;
    		std::cin >> t;
    		g[i] += !t << j;
    	}

    for (int i = 0; i < 1 << m; ++i) 
    	if (!(i & i >> 1))
    		state.eb(i);
    for (auto a : state)
    	for (auto b : state)
    		if (!(a & b))
    			head[a].eb(b);

    f[0][0] = 1;

    for (int i = 0; i <= n + 1; ++i)
    	for (int a : state)
    		for (int b : head[a])
    			if (g[i] & a) continue;
    			else {
    				f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
    			}

    std::cout << f[n + 1][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
