#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::array<int, 2>> a(n), b(m);
    // 板子题 加油
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    	a[i][1] = i;
    }
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i][0];	
    	b[i][1] = i;
    }

    std::set<std::array<int, 2>> st;
    for (int i = 0; i < k; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	st.insert({x - 1, y - 1});
    }
    
    std::ranges::sort(a, std::greater());
    std::ranges::sort(b, std::greater());
    std::priority_queue<std::array<int, 3>> pq;

    for (int i = 0; i < n; ++i) {
    	pq.push({a[i][0] + b[0][0], i, 0});
    }
    
    while (1) {
    	auto [val, i, j] = pq.top();
    	pq.pop();
    	if (!st.count({a[i][1], b[j][1]})) {
    		std::cout << val << "\n";
    		return;
    	}
    	if (j + 1 < m) {
    		pq.push({a[i][0] + b[j + 1][0], i, j + 1});
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
