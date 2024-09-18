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
using pii = std::pair<int, int>;
const int N = 1e5 + 13;

/*
https://codeforces.com/contest/1141/submission/192610240

暴力统计每个子数组的和，用哈希表把和相同的子数组左右端点记录下来。
对于每一组，问题变成最多不重叠线段个数。
这是个经典贪心，按照右端点从小到大排序+遍历，一旦遇到左端点大于上一个记录的右端点，答案加一，更新右端点。
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<pii> ans, res;
    std::vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	s[i] = s[i - 1] + a[i];
    }

    std::map<int, std::vector<pii>> mp;
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= i; ++j)
    		mp[s[i] - s[j - 1]].eb(j, i);
    for (auto&[_, v] : mp) {
    	res.clear();
    	std::sort(all(v), [&](auto v1, auto v2){
    		return v1.second < v2.second;
    	});
    	for (auto[l, r] : v) {
    		if (res.empty() || l > res.back().second) {
    			res.eb(l, r);
    		}
    	}
    	if (sz(res) > sz(ans)) ans = res;
    }
    std::cout << sz(ans) << "\n";
    for (auto[l, r] : ans) std::cout << l << " " << r << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
