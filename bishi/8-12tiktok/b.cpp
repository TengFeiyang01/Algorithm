#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

int getMaxGoodSubarrayLengeh(int limit, vector<int> financialMetrics) {
	int n = financialMetrics.size();
	std::vector<int> left(n, -1), right(n, n);
	std::stack<int> stk;
	for (int i = 0; i < n; ++i) {
		int x = financialMetrics[i];
		while (stk.size() and financialMetrics[stk.top()] >= x) {
			stk.pop();
		}
		if (stk.size()) {
			left[i] = stk.top();
		}
		stk.push(i);
	}
	stk = stack<int>();
	for (int i = n - 1; i >= 0; --i) {
		int x = financialMetrics[i];
		while (stk.size() and financialMetrics[stk.top()] >= x) {
			stk.pop();
		}
		if (stk.size()) {
			right[i] = stk.top();
		}
		stk.push(i);
	}
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		i64 x = financialMetrics[i];
		if (x * (right[i] - left[i] - 1) > limit) {
			ans = max(ans, right[i] - left[i] - 1);
		}
	}
	return ans;
}


void solve() {
	int n, limit;
	std::cin >> n >> limit;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::cout << getMaxGoodSubarrayLengeh(limit, a);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
