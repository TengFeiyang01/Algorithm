#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

void solve() {
    int n, m;
    i64 ans = 0;
    std::cin >> n >> m;
    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    	auto mn = a[i];
    	std::vector<i64> pre(m + 1);
    	for (int up = i; up >= 0; --up) {
    		i64 s = 0;
    		for (int j = 0; j < m; ++j) {
    			mn[j] = std::min(mn[j], a[up][j]);
    			s += a[up][j];
    			pre[j + 1] += s;
    		}
        	std::vector<int> posL(m), posR(m, m);
        	std::stack<int> stk;
        	stk.push(-1);
        	for (int j = 0; j < m; ++j) {
        		while (stk.size() > 1 && mn[j] < mn[stk.top()]) {
        			posR[stk.top()] = j;
        			stk.pop();
        		}
        		posL[j] = stk.top();
        		stk.push(j);
        	}
        	for (int j = 0; j < m; ++j) {
        		ans = std::max(ans, i64(pre[posR[j]] - pre[posL[j] + 1]) * mn[j]);
        	}
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