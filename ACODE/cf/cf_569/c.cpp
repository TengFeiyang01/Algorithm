#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    std::deque<int> q;
    std::vector<std::array<int, 2>> p;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	q.push_back(x);
    	mx = std::max(mx, x);
    }

    int len = 0;
    while (q.front() != mx) {
    	int x = q[0], y = q[1];
    	q.pop_front();
    	q.pop_front();
    	if (x > y) {
    		q.push_front(x);
    		q.push_back(y);
    	} else {
    		q.push_front(y);
    		q.push_back(x);
    	}
    	p.push_back({x, y});
    	len++;
    }
    
    std::vector<int> cycle;
    q.pop_front();


    for (int i = 0; i < m; ++i) {
    	i64 d;
    	std::cin >> d;
    	if (d >= 1 and d <= len) {
    		std::cout << p[d - 1][0] << " " << p[d - 1][1] << "\n";
    	} else {
    		d -= len;
    		d %= n - 1;
    		if (d == 0) {
    			std::cout << mx << " " << q.back() << "\n";
    		} else {
    			std::cout << mx << " " << q[d - 1] << "\n";
    		}
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}