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
using PII = std::pair<ll, std::pair<int, int>>;
const int N = 1e5 + 13;

struct cow{
	ll price, cost;
}a[50002];

/*
	首先可以确定，在最优解中，k张优惠券一定会用光（除非带的钱实在太少）
	于是一开始先选中c最小的前k只牛。可以证明，最优解中一定包含这些牛，然而优惠券却不一定全部用在它们身上。
		假设后来不买这其中的牛i，而是转而用优惠价买了这之外的牛j，发现 cj>ci 绝对是亏的。
		
		假设最后决定用原价买这其中的牛i，用腾出来的优惠券买了这之外的牛j，发现pi+cj<ci+pj
		是有可能存在的，此时pj−cj>pi−ci，也即牛j的折扣量比牛i的折扣量要大，
		这时候把优惠券用在牛j身上是更优的，那这样也是可行的
	
	接下来继续买牛。如果要买一只牛j，可以按原价买，也可以取消已经选中的牛i的折扣来用优惠价买牛j，
	二者分别花费pj和cj+pi−ci。我们需要每次都选出最便宜的牛，这个用优先队列即可。

*/

void solve() {
    int n, k;
	ll m, sum = 0;
	std::cin >> n >> k >> m;

	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> p;

	for (int i = 1; i <= n; ++i) {
		auto&[p, c] = a[i];
		std::cin >> p >> c;
	}

	std::sort(a + 1, a + n + 1, [&](auto cow1, auto cow2) {
		return cow1.cost < cow2.cost;
	});

	for (int i = 1; i <= k; ++i) {
		sum += a[i].cost;
		if (sum > m) {
			std::cout << i - 1;
			return;
		}
		p.push(a[i].price - a[i].cost);
	}

	std::sort(a + k + 1, a + n + 1, [&](auto c1, auto c2) {
		return c1.price < c2.price;
	});

	for (int i = k + 1; i <= n; ++i) {
		int u = a[i].price - a[i].cost;
		if (u > p.top()) {
			sum += p.top();
			p.pop();
			p.push(u);
			sum += a[i].cost;
		} else {
			sum += a[i].price;
		}

		if (sum > m) {
			std::cout << i - 1;
			return;
		}
	}
	std::cout << n;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
