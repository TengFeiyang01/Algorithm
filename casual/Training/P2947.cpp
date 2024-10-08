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
const int N = 3e6 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(1 + n);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::stack<int> stk;
	//右侧第一个大于他的
	std::vector<int> l(n + 1);
	for (int i = n; i >= 1; --i) {
		while (sz(stk) && a[stk.top()] <= a[i]) stk.pop();
		if (sz(stk)) l[i] = stk.top();
		else l[i] = 0;
		stk.push(i);
	}
	for (int i = 1; i <= n; ++i) std::cout << l[i] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
