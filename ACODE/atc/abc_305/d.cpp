#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n), s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (i) {
    		if (i % 2 == 0) {
    			s[i] += a[i] - a[i - 1];
    		}
    		s[i] += s[i - 1];
    	}
    	// std::cout << s[i] << " \n"[i == n - 1];
    }
    std::cin >> m;
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		int p = std::upper_bound(a.begin(), a.end(), l) - a.begin();
		int q = std::upper_bound(a.begin(), a.end(), r) - a.begin();
		
		int ans = 0;
		if (q == n) {
			ans = s.back();
		} else {
			ans = s[q];
			if (q % 2 == 0) ans -= a[q] - r;
			
		}
		// std::cout << p << " " << q << " ";
		ans -= s[p - 1];
		
		if (p % 2 == 0) {
			ans -= l - a[p - 1];
		}

		std::cout << ans << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
