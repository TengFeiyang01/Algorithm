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
    int n, k, t, q, s = 0;
    std::vector<int> g[3];
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	int a, b;
    	std::cin >> t >> a >> b;
    	if (a && b) g[0].eb(t);
      	else if (a && !b) {
      		g[1].eb(t);
      	} else if (!a && b) {
      		g[2].eb(t);
      	}
    }
    for (int i = 0; i < 3; ++i) std::sort(all(g[i]));
    int lena = g[0].size(), lenb = g[1].size(), lenc = g[2].size();
    int a = 0, b = 0, c = 0;
	while (a < lena && k) {
		if (b < lenb && c < lenc && a < lena) {
			if (g[0][a] <= g[1][b] + g[2][c]) {
				s += g[0][a++];
			} else {
				s += g[1][b++] + g[2][c++];
			}
		} else {
			s += g[0][a++];
		}
		--k;
	}
	while (b < lenb && c < lenc && k) {
		s += g[1][b++] + g[2][c++];
		k--;
	}
	if (k > 0) {
		std::cout << "-1\n";
	} else {
		std::cout << s << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
