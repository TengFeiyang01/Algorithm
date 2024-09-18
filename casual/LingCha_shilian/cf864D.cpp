#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), cnt(n + 2);
    std::vector<bool> skip(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 0, cur = 1;

    for (int i = 0; i < n; ++i) {
    	if (cnt[a[i]] == 1) continue;
    	while (cnt[cur] > 0) cur++;
    	if (cur > a[i] && !skip[a[i]]) {
    		skip[a[i]] = true;
            continue;
    	}
    	cnt[a[i]]--;
    	a[i] = cur++;
    	ans++;
    }

    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
    	std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}