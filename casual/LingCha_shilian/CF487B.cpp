#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, s, L;
    std::cin >> n >> s >> L;
    std::vector<int> a(n + 1);
    std::deque<int> small, big, q;
    std::vector<int> f(n + 1, inf);
    f[0] = 0;
    int l = 1;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	while (small.size() and a[small.back()] >= a[i]) {
    		small.pop_back();
    	}
		small.push_back(i);
    	while (big.size() and a[big.back()] <= a[i]) {
    		big.pop_back();
    	}
		big.push_back(i);
		for (; l <= i; ++l) {
			while (small.front() < l) small.pop_front();
			while (big.front() < l) big.pop_front();
			if (a[big.front()] - a[small.front()] <= s) break;
		}
		if (i < L) continue;

		while (q.size() and f[q.back()] >= f[i - L]) {
			q.pop_back();
		}
		q.push_back(i - L);
		while (q.size() and q.front() < l - 1) q.pop_front();
		if (l <= i - L + 1 and q.size()) {
			f[i] = f[q.front()] + 1;
		}
    }
    if (f[n] >= inf) {
    	f[n] = -1;
    }
    std::cout << f[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}