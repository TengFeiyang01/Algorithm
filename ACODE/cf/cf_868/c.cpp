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
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	for (int j = 2; j * j <= x; ++j) {
    		if (x % j == 0) {
    			while (x % j == 0) {
    				x /= j;
    				cnt[j] += 1;
    			}
    		}
    	}
    	if (x > 1) cnt[x] += 1;
    }
    int ans = 0, res = 0;
    for (auto[_, x] : cnt) {
    	ans += x / 2;
    	res += x % 2;
    }
    std::cout << ans + res / 3 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
