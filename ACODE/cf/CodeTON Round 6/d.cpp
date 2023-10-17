#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    std::map<int, int> r;
    std::vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i];
    	r[c[i]] = i;
    	a[i] = 0;
    	b[i] = c[i];
    }
    std::cin >> k;
   	
    int idx = 0;
    for (int i = 0; i < n; ++i) {
    	if (c[idx] >= c[i]) {
    		idx = i;
    	}
    }

    for (int i = n - 2; i >= 0; --i) b[i] = std::min(b[i], b[i + 1]);
    int p = k / c[idx];
	
	a[idx] = p;
	
	int left = k % c[idx], pre = idx;
	for (int i = idx + 1; left and i < n; ++i) {
		if (c[i] != b[i] or i != r[c[i]]) {
			continue;
		}
		if ((c[i] - c[pre]) > left) {
			break;
		}
		int t = c[i] - c[pre];
		p = std::min(a[pre], left / t);
		a[pre] -= p;
		a[i] = p;
		left -= t * p;

		pre = i;
	}
	for (int i = n - 2; i >= 0; --i) {
		a[i] += a[i + 1];
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " \n"[i == n - 1];
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