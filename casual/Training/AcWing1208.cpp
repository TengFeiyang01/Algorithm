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

void C(std::string &s) {
	for (auto& c : s) {
		if (c == '*') c = '1';
		else c = '0';
	}
}

void solve() {
    std::string a, b;
    std::cin >> a >> b;
	C(a);C(b);
	int ans = 0;
	for (int i = 0; i < sz(a) - 1; ++i) {
		if (a[i] != b[i]) {
			ans++;
			a[i] ^= 1;
			a[i + 1] ^= 1;
		}
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
