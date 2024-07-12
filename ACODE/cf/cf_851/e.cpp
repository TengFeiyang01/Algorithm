#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

//题意 将数组分为若干区间 (每个区间内元素和大于0) 求所有区间长度和的最大值
//思路 定义f[i]为以a[i]结尾的划分的最大值
//不选a[i] f[i] = f[i - 1]
//选a[i] 找s[j] <= s[i] and j < i 的 j 使得 f[j] + i - j 最大化
//我们可以将f[j]-j视为整体 那么每次求的是小于当前s[i]的下标j中的f[j]-j的最大值 
//使用树状数组优化即可

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	s[i] = (a[i] += a[i - 1]);
    }
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    int m = s.size();
    auto find = [&](i64 x) ->int {
    	return std::lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
    };

    std::vector<int> tr(m + 1, -inf);

    auto add = [&](int x, int v) {
    	for (int i = x; i <= m; i += i & -i) {
    		tr[i] = std::max(tr[i], v);
    	}
    };

    auto query = [&](i64 x) ->int {
    	int res = -inf;
    	while (x) {
    		res = std::max(res, tr[x]);
    		x &= x - 1;
    	}
    	return res;
    };

    std::vector<int> f(n + 1);

    for (int i = 1; i <= n; ++i) {
    	add(find(a[i - 1]), f[i - 1] - i + 1);
    	f[i] = std::max(f[i - 1], query(find(a[i])) + i);
    }
    std::cout << f[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
