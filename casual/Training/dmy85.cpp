#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1), left(n + 2), right(n + 2), l(n + 2), r(n + 2), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]] = i;
    }
    for (int i = 0; i <= n + 1; ++i) {
    	l[i] = std::max(0, i - 1);
    	r[i] = std::min(i + 1, n + 1);
    }

    i64 ans = 0;
    // 每次遍历玩这个数之后 删除这个数
    for (int i = 1; i <= n; ++i) {
    	int x = pos[i];
    	left[0] = x;
    	for (int j = 1; j <= k; ++j) {
    		x = l[x];
    		left[j] = x;
    	}
    	x = pos[i];
        right[0] = x;
    	for (int j = 1; j <= k; ++j) {
    		x = r[x];
    		right[j] = x;
    	}
        x = pos[i];
    	l[r[x]] = l[x];
    	r[l[x]] = r[x];
    	i64 seg = 0;

    	for (int j = 1; j <= k; ++j) {
    		seg += i64(left[j - 1] - left[j]) * (right[k - j + 1] - right[k - j]);
    	}
    	ans += seg * i;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
