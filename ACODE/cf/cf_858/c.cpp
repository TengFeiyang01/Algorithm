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
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n * 2);
    for (auto&x : a) std::cin >> x;
    if (n == 1) {
    	std::cout << abs(a[0] - a[1]) << "\n";
    	return;
    }
   	std::sort(all(a));

    if (n % 2 == 0) {
    	ll ans1 = 0;
    	for (int i = 0; i < 2 * n - 1; ++i) {
    		ans1 += abs(a[i] + 1);
    	}
    	ans1 += abs(a[n * 2 - 1] - n);
    } else {
    	ll ans = 0;
    	for (int i = 0; i < 2 * n - 1; ++i) {
    		ans += abs(a[i] - 1);
    	}
    	ans += abs(a[n * 2 - 1] - n);
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
