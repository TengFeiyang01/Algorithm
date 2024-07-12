#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 s = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    	if (i) {
    		a[i] += a[i - 1]; // 前缀和
    	}
    }
    if (s % 3) {
    	std::cout << "-1\n";
    	return;
    }
    i64 s1 = s / 3, s2 = s / 3 * 2;

    int cnt = 0;
    // 保证第三个数组至少有一个元素
    for (int i = n - 2; i >= 0; --i) {
    	// cnt 是满足条件的j的个数
    	if (a[i] == s1) {
    		// 以[0, i] [i+1, j], [j + 1, n-1]
    		ans += cnt;
    	}
    	if (a[i] == s2) {
    		cnt++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
