#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <stack>
#include <unordered_map>

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    std::vector<int> a(n + 1), l(n + 1), r(n + 1);
    std::stack<int> s;

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
    	while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    	if (!s.empty()) l[i] = s.top() + 1;
    	else l[i] = 1;
    	s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n; i >= 1; --i) {
    	while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    	if (!s.empty()) r[i] = s.top() - 1;
    	else r[i] = n;
    	s.push(i);
    }

    std::vector<int> ans(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
    	ans[r[i] - l[i] + 1] = std::max(ans[r[i] - l[i] + 1], a[i]);
    }

    for (int i = n; i >= 1; --i) {
    	ans[i] = std::max(ans[i + 1], ans[i]);
    }

    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
