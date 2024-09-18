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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
ll n, m, nums[N];
ll x, y;

void solve() {
    std::cin >> n >> x >> y;
   	std::string a, b;
   	std::cin >> a >> b;
   	int cnt = 0;
   	std::vector<int> pos;
   	for (int i = 0; i < a.size(); ++i) {
   		if (a[i] != b[i]) {
   			pos.emplace_back(i);
   			cnt++;
   		}
   	}
    /*
        首先统计 a[i] != b[i] 的 i，记到数组 p 中，由于每次操作只能改变 2 个这样的 i，那么如果 p 的长度是奇数，则输出 −1。
    */
    //分类讨论：y ≤ x 和 y > x。
   	if (cnt % 2 == 1) {
   		std::cout << "-1\n";
        return;
   	}
    int m = pos.size();
   	if (m == 0 || y <= x) {
        //如果 m == 2 且相邻 有两种情况
        //case 1 直接取反 cost = x;
        //case 2 选不相邻的 分别处理 cost = y * 2;
   		if (2 == m && pos[0] == pos[1] - 1) {
   			std::cout << std::min(2 * y, x) << "\n";
   		} else {
            //否则的话 每次取不相邻的处理  m / 2 * y
   			std::cout << m / 2 * y << "\n";
   		}
   		return;
   	} else {
        //y > x 时
        //设 f[i] 表示修改 p 的前 i 个位置的最小花费，那么对于 p[i]，有两种方案：
        //case 1: 找个不相邻的位置操作，花费 y，那么对于 p[i] 相当于花费 y/2，因此 f[i]=f[i−1]+y/2
        //case 2: 不断找相邻的位置操作,把 p[i] 和 p[i−1] 一组，那么需要操作 p[i]−p[i−1] 次，因此 f[i]=f[i−2]+(p[i]−p[i−1])⋅x
        //每次转移取最小值 f[i]=min(f[i−1]+y/2,f[i−2]+(p[i]−p[i−1])⋅x)
        //初始值 f[0]=0，f[1]=y，答案为 f[m]。
        //为了方便处理 y/2，可以把所有数都乘 2，最后再除以 2。
        ll f[m + 1]{0};
   		f[1] = y;
   		for (int i = 1; i < m; ++i) {
   			f[i + 1] = std::min(f[i] + y, f[i - 1] + (ll)(pos[i] - pos[i - 1]) * x * 2);
   		}
   		std::cout << f[m] / 2 << "\n";
   		return;
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
