#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

constexpr int mod = 998244353;

void solve() {
    i64 n = 1, m, ans = 1;
    std::cin >> m;
    
    std::vector<int> p(m, 1);
    for (int i = 1; i < m; ++i) {
        p[i] = (p[i - 1] * 10LL % mod + mod) % mod;
    }

    int cnt = 0;

    std::deque<int> q;
    q.push_back(1);

    while (m--) {
    	int x, op;
    	std::cin >> op;
    	if (op == 1) {
    		int x;
            cnt++;
    		std::cin >> x;
    		q.push_back(x);
    		ans = ans * 10 + x;
    		ans %= mod;
    	} else if (op == 2) {
    		ans -= (1LL * q.front() * p[cnt]) % mod;
    		ans = (ans + mod) % mod;
    		cnt--;
            q.pop_front();
    	} else {
    		std::cout << ans << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
