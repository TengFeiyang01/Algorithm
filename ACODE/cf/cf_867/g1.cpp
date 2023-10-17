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
const int N = 1e6 + 1;
int cnt[N]{0};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]] += 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (cnt[a[i]] >= 3) {
    		ans += (cnt[a[i]] - 1LL) * (cnt[a[i]] - 2);
    	}
    }
    for (int i = 0; i < n; ++i) {
    	int t = 1000000 / a[i];
    	for (int j = 2; j <= t / j; ++j) {
    		ans += 1LL * cnt[a[i] * j] * cnt[a[i] * j * j];
    	}
    }
    std::cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
    	cnt[a[i]] = 0;
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
