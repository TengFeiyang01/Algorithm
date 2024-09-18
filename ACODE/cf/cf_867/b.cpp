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
    std::vector<ll> a(n);
    int zero = 0;
    std::vector<ll> pos, neg;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] == 0) zero = 1;
    	else if (a[i] > 0) {
    		pos.emplace_back(a[i]);
    	} else {
    		neg.emplace_back(a[i]);
    	}
    }
    std::sort(a.begin(), a.end());
    // std::sort(pos.begin(), pos.end());
    // std::sort(neg.begin(), neg.end());
    // ll ans = -1e18;
    // if (pos.size() >= 2) {
    // 	int m = pos.size() - 1;
    // 	ans = std::max(ans, pos[m] * pos[m - 1]);
    // }
    // if (neg.size() >= 2) {
    // 	int m = neg.size() - 1;
    // 	ans = std::max(ans, neg[0] * neg[1]);
    // }
    // if (zero) {
    // 	ans = std::max(ans, 0LL);
    // }
    // if (pos.size() and neg.size()) {
    //     ans = std::max(ans, neg.back() * pos[0]);
    // }
    std::cout << std::max(a[0] * a[1], a[n - 1] * a[n - 2]) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
