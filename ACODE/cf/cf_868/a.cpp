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
    int n, ans, k;
    std::cin >> n >> k;
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
    	if (i * (i - 1) + (n - i) * (n - i - 1) == 2 * k) {
    		ok = true;
    		ans = i;
    	}
    }
    if (!ok) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n";
    	for (int i = 0; i < ans; ++i) {
    		std::cout << "1 ";
    	}
    	for (int i = ans; i < n; ++i) {
    		std::cout << "-1 ";
    	}
    	std::cout << "\n";
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
