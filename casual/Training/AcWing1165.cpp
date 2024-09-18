#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, double>;
const int N = 700;

void solve() {
	int n;
    while (std::cin >> n, n) {
		std::vector<PII> g[N];
    	std::vector<double> dist(N);
    	for (int i = 1; i <= n; ++i) {
	    	std::string s;
	    	std::cin >> s;
	    	if (s.size() >= 2) {
	    		int l = (s[0] - 'a') * 26 + (s[1] - 'a');
	    		int r = (s[s.size() - 2] - 'a') * 26 + (s.back() - 'a');
	    		g[l].emplace_back(r, s.size());
	    	}
	    }	
	    	auto check = [&](double mid) {
	    		std::vector<int> st(N), cnt(N);
	    		std::queue<int> q;
	    		for (int i = 0; i < 676; ++i) {
	    			q.push(i);
	    			st[i] = 1;
	    		}

	    		int count = 0;
	    		while (q.size()) {
	    			int t = q.front(); q.pop();
	    			st[t] = 0;

	    			for (auto&[j, w] : g[t]) {
	    				if (dist[j] < dist[t] + w - mid) {
	    					dist[j] = dist[t] + w - mid;
	    					cnt[j] = cnt[t] + 1;

	    					if (++count > 10000) return true;
	    					if (cnt[j] >= N) return true;
	    					if (!st[j]) {
	    						st[j] = 1;
	    						q.push(j);
	    					}
	    				}
	    			}
	    		}
	    		return false;
	    	};

	    	if (!check(0)) {
	    		std::cout << "No solution" << "\n";
	    		return;
	    	} else {
	    		double l = 0, r = 1000;
	    		while (r - l > 1e-4) {
	    			double mid = (l + r) / 2;
	    			if (check(mid)) l = mid;
	    			else r = mid;
	    		}
	    		std::cout << r << "\n";
	    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
