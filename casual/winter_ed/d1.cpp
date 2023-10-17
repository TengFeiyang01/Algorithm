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
const int N = 5e5 + 31;
int n, l[N], r[N];
/*
记录每头牛左右两边有多少连续的不同种类的牛,计算这头牛的孤独照片，分三类：
1. 这头牛在照片中间，左牛数乘右牛数，l[i] * r[i]
2. 在照片左端点，照片长度至少3，右边有一头牛的情况不合格，r[i]可能< 1 ,max(r[i] - 1, 0)
3. 在照片右端点，同理
*/

void solve() {
	ll ans = 0ll;
	std::string s;
    std::cin >> n >> s;
    for (int i = 0, g = 0, h = 0; i < n; ++i) {
    	if (s[i] == 'H') l[i] = g, g = 0, h++;
    	else l[i] = h, h = 0, g++;
    }
    for (int i = n - 1, g = 0, h = 0; i >= 0; --i) {
    	if (s[i] == 'H') r[i] = g, g = 0, h++;
    	else r[i] = h, h = 0, g++;
    }
    for (int i = 0; i < n; ++i) {
    	if (l[i] + r[i] > 1) {
    		ans += ll(l[i]) * r[i] + std::max(0, l[i] - 1) + std::max(0, r[i] - 1);
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
