#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    std::ranges::sort(a);
    std::priority_queue<int> q;
    i64 sum = 0;
    std::vector<i64> ans(n + 1, -1);
    for (int i = 0; i <= n; ++i) {
    	ans[i] = sum + cnt[i];
    	if (cnt[i]) {
    		while (cnt[i]-- > 1) {
    			q.push(i);
    		}
    	} else {
    		if (q.empty()) break;
    		sum += i - q.top();
    		q.pop();
    	}
    }
    for (int i = 0; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
