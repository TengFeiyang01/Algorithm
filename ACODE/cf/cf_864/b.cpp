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
    int n, m, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    		std::cin >> a[i][j];
    int need = 0;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    		if (a[i][j] != a[n - i - 1][n - j - 1])
    			need++;

    //std::cout << need << "\n";
    need /= 2;
    if (need <= k) {
        if ((n % 2 == 0 and (need - k) % 2 == 0) or (n % 2))
        	std::cout << "YES\n";
        else if (n % 2 == 0 and (need - k) % 2) {
            std::cout << "NO\n";
        }
    } else {
    	std::cout << "NO\n";
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
