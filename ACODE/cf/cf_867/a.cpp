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
    int n, t;
    std::cin >> n >> t;
    int la = 0;
    int ans = -1, mx = -1;
    std::vector<int> a(n), b(n);
    for (int &c : a) std::cin >> c;
    for (int &c : b) std::cin >> c;
    for (int i = 0; i < n; ++i) {
    	int x = a[i], y = b[i];
    	if (la + x <= t) {
    		if (y > mx) {
    			ans = i + 1;
    			mx = y;
    		}
    	}
    	la++;
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