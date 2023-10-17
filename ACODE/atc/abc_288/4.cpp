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
    std::vector<ll> a(n);
    std::vector<ll> dif(n, 0);
    std::vector<ll> sum(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

  	for (int i = 0; i < n - k; ++i) {
		if (i) dif[i] += dif[i - 1];
		if (a[i] + dif[i] != 0) {
			dif[i] += -(a[i] + dif[i]);
			dif[i + k] += (a[i] + dif[i]);
		}

  	}
  	for (int i = 0; i < n; ++i) {
  		std::cout << dif[i] << " \n"[i == n - 1];
  	}

	int q;
	std::cin >> q;

	while (q--) {

	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
