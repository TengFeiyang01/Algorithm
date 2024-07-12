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
    std::vector<int> a(n + 1), b(n + 1);
    std::map<int, int> cnt, cnt2;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	if (a[i] != a[i - 1]) {
    		s = 1;
    	} else {
    		s++;
    	}
    	cnt[a[i]] = std::max(cnt[a[i]], s);
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    	if (b[i] != b[i - 1]) {
    		s = 1;
    	} else {
    		s++;
    	}
    	cnt2[b[i]] = std::max(cnt2[b[i]], s);
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; ++i) {
    	ans = std::max(ans, cnt2[i] + cnt[i]);
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
