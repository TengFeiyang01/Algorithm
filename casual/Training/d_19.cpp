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
using ll = unsigned long long;
using PII = std::pair<int, int>;

void solve() {
	ll a, b;
	std::cin >> a >> b;
	ll ans = 1;

	while (b) {
		if (b & 1) ans *= a;
		
		if (ans > 1000000000 || a > 1000000000) {
			std::cout << "-1\n";
			return;
		}
		
		a *= a;
		b /= 2;
	}    
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
