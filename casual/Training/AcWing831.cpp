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

int ne[N]{0};

void solve() {
	int n, m;
	std::string s, p;
	std::cin >> n >> p >> m >> s;
	s = " " + s;
	p = " " + p;

	for (int i = 2, j = 0; i <= n; ++i) {
		while (j & p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) ++j;
		ne[i] = j;
	}

	for (int i = 1, j = 0; i <= m; ++i) {
		while (j & s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) ++j;
		if (j == n) {
			std::cout << i - n + 1 << " ";
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
