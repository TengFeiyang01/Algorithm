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

// 方法一
/*void solve() {
	auto query = [&](int x) {
		std::cout << "- " << x << "\n";
		int t;
		std::cin >> t;
		return t;
	};
	int cnt;
	std::cin >> cnt;
	int last = 1, ans = 0;
	while (cnt > 0) {
		int t = query(last);
		//t是新的位数 如果t比cnr大 说明lowbit 不在最低位， 新增的1的个数+1就是lowbit所在的位
		ans |= (1 << (t - cnt + 1));
		last = (1 << (t - cnt + 1));
		cnt--;
	}
	std::cout << "! " << ans << "\n";
}*/


//我们可以通过操作找到lowbit.
//我们考虑这样的操作,每次我们都减去1,然后就可以根据位数的变化来推断出lowbit在什么位置
//,然后我们把lowbit及以后的位都清空,继续这个操作,这样就可以知道所有的lowbit的位置.

void solve() {
	auto query = [&](int x) {
		std::cout << "- " << x << "\n";
		int t;
		std::cin >> t;
		return t;
	};
	int cnt;
	std::cin >> cnt;
	int ans = 0, last = 0;
	while (cnt > 0) {
		//每次减一 先将减去的1加上
		int t = query(1 + last);
		//t是新增的
		//back表示Lowbit所在位置
		int back = t - cnt + 1;
		ans |= (1 << back);
		last = (1 << back) - 1;
		cnt--;
	}
	std::cout << "! " << ans << "\n";
}

int main() {
/*    std::cin.sync_with_stdio(false);
    std::cin.tie(0);*/

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
