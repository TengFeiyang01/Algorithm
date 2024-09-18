#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int S = 1e6, N = 1e9;

std::vector<int> get_fac(int n) {
	std::vector<int> f;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			f.emplace_back(i);
			if (i * i != n) f.emplace_back(n / i);
		}
	}
	return f;
}

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	mp[x] += 1;
    }
    ll ans = 0;
    for (auto&[x, y] : mp) {
    	ans += 1LL * y * (y - 1) * (y - 2);
    	if (x >= S) {
    		for (int j = 2; 1LL * j * x <= N; ++j)
    			if (x % j == 0 and mp.count(x * j) and mp.count(x / j)) {
    				ans += 1LL * y * mp[x * j] * mp[x / j];
    			}
    	} else {
    		auto f = get_fac(x);
    		std::sort(f.begin(), f.end());
    		for (int &u : f) {
    			if (u == 1) continue;
    			if (1LL * x * u > N) continue;
    			if (mp.count(x / u) and mp.count(x * u)) {
    				ans += 1LL * y * mp[x / u] * mp[x * u];
    			} 
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
