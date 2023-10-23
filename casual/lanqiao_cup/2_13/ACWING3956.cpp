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

//因为要把数组均分三份，总和一定得是3的倍数
//遍历前缀和数组，边扫描边记录哪些地方可以切第一刀，哪些地方可以切第二刀。如果位置j可以切第二刀，那么它与前面第一刀进行组合，就可以切成三部分。
//切第一刀的判断条件是：s[i]==t；
//处理方法是：cnt++（cnt的意思就是i位置前面有多少可以切第一刀的地方）
//切第二刀的判断条件是：s[n]-s[i+1]==t
//处理方法是：ans+=cnt，第二刀跟前面的cnt个第一刀组合，所以总个数增加cnt个

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i < n - 1; ++i) a[i + 1] += a[i];
	ll s = a.back();
	if (s % 3) {
		std::cout << "0";
	} else {
		ll t = s / 3, ans = 0;
		for (int i = 0, cnt = 0; i < n - 2; ++i) {
			if (a[i] == t) cnt++;
			if (s - a[i + 1] == t) ans += cnt;
		}
		std::cout << ans;
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
