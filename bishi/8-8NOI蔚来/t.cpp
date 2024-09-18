#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    i64 ans = 0;
    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
    	if (pq.size() and x > pq.top()) {
   	    	ans += x - pq.top();
    		pq.pop();
            // 反悔
	    	pq.push(x);
    	}
        // 贪心
    	pq.push(x);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
