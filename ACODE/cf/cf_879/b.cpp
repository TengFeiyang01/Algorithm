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
    std::string a, b;
    std::cin >> a >> b;
    int x = a.size(), y = b.size();
    int ans = 0;
    int n = y;
    if (x < y) {
    	std::string z(abs(y - x), '0');
    	a = z + a;
    }
    int ok = 0;
    for (int i = 0; i < std::max(x, y); ++i) {
    	if (a[i] == b[i]) continue;
    	ans += std::abs(a[i] - b[i]);
    	ans += (n - i - 1) * 9;
        std::cout << ans << "\n";
    	return;
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
