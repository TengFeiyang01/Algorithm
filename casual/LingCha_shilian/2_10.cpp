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
const int mod = 1e9 + 7;

/*
https://codeforces.com/contest/1361/submission/192575286

提示：从大到小遍历 k，栈，消消乐

例如 p=3，k=[4,3,3,2,2,1,1,1]，第一个 4 放一组，剩余的放另一组。在遍历的时候为了判断能否抵消，需要用到栈来统计 k[i] 及其出现次数，如果凑齐 p 个，那么就可以合成一个更大的 k。

为什么一定可以消除？因为小的 p**k 一定是大的 p**k 的因子。
*/

void solve() {
    ll n, p;
    std::cin >> n >> p;
    std::vector<int> a(n);
    for (int&v : a) std::cin >> v;

   	auto pow = [&](int t) ->ll {
   		ll res = 1;
   		for (ll x = p; t > 0; t >>= 1) {
   			if (t & 1) res = res * x % mod;
   			x = x * x % mod;
   		}
   		return res;
   	};
	
	if (p == 1) {
		std::cout << n % 2 << "\n";
		return;
	}	

	std::sort(all(a));

	int tk = a[n - 1];

	std::stack<PII> s;
	for (int i = n - 2; i >= 0; --i) {
		int k = a[i];
		while (s.size() && s.top() == (PII){k, p - 1}) {
			s.pop();
			k++;
		}
		if (k == tk) {
			if (i == 0) {
				std::cout << "0\n";
				return;
			}
			--i;
			tk = a[i];
		} else if (s.size() && s.top().first == k) {
			s.top().second++;
		} else {
			s.push({k, 1});
		}
	}
	ll ans = pow(tk);
	while (s.size()) {
		auto[k, c] = s.top();
		s.pop();
		ans -= pow(k) * (ll)c;
	}
	std::cout << ((ans % mod) + mod) % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
