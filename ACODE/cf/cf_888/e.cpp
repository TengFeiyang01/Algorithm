#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> c(n), p(k);

    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i];
    }
    std::vector<i64> f(n);
    for (int i = 0; i < k; ++i) {
    	std::cin >> p[i];
    	c[p[i] - 1] = 0;
    }

    std::vector<int> d(n);
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
    	int m;
    	std::cin >> m;
    	for (int j = 0; j < m; ++j) {
    		int x;
    		std::cin >> x;
    		a[x - 1].push_back(i);
    		d[i]++;
    	}
    }
    
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
    	if (d[i] == 0) {
    		q.push(i);
    		f[i] = c[i];
    	}
    }

    while (q.size()) {
    	auto u = q.front();
    	q.pop();
    	for (auto v : a[u]) {
    		f[v] += f[u];
    		if (--d[v] == 0) {
    			q.push(v);
    			f[v] = std::min(f[v], c[v]);
    		}
    	}
    }


    for (int i = 0; i < n; ++i) {
    	std::cout << f[i] << " \n"[i == n - 1];
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
