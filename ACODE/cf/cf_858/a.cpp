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
    ll a, b, c, d;
    std::cin >> a >> b >> c >> d;
    ll x = c - a;
    ll y = d - b;

    if (d - b < 0) {
    	std::cout << "-1\n";
    	return;
    }

    if (y == x and y >= 0) {
    	std::cout << y << "\n";
   		return;
    } 

    if (y < x) {
    	std::cout << "-1\n";
    	return;
    } 

    ll ans = y + (abs(a + y - c));
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
