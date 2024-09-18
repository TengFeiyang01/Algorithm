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

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<ll> s(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> s[i];
    	s[i] += s[i - 1];
    }

    std::vector<ll> f(n + 1, 0LL);
    


    auto g = [&](int x) ->ll {
    	if (x == 0) return 0;
    	return f[x - 1] - s[x];
    };
	
	std::vector<int> q(n + 2, 0);
	int tt = 0, hh = 0;
	for (int i = 1; i <= n; ++i) {
		if (q[hh] < i - m) ++hh;
		f[i] = std::max(f[i - 1], g(q[hh]) + s[i]);
		while (hh <= tt && g(q[tt]) <= g(i)) tt--;
		q[++tt] = i;
	}
	std::cout << f[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
