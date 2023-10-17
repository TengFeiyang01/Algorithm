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
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
	int len = 0;
	for (len = n - 1; len > 0; --len) {
		if (s.substr(0, len) == s.substr(n - len)) {
			break;
		}
	}
	if (len == 0) {
		auto t = s;
		while (--k) {
			s += t;
		}
		std::cout << s;
		return;
	} else {
		auto t = s.substr(len);
		while (--k) {
			s += t;
		}
		std::cout << s;
	}

	
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
