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


//判定是否存在子段和大于sum
void solve() {
    int n;
    ll sum = 0;
    std::cin >> n;
    std::vector<ll> a(n + 1);

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	sum += a[i];
    }
   	auto f = [&](int st, int ed)->ll{
		ll res = -inf, cur = 0LL;
		for (int i = st; i <= ed; ++i) {
            cur += a[i];
			res = std::max(res, cur);
		    if (cur < 0) cur = 0;
        }   		
		return res;
   	};

   	if (sum > std::max(f(1, n - 1), f(2, n))) {
   		std::cout << "YES\n";
   	} else {
   		std::cout << "NO\n";
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
