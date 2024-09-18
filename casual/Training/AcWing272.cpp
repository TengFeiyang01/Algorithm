#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> b[i];

    vector f(n + 1, std::vector<int>(n + 1, 0));
	
	int ans = 0;

    for (int i = 1; i <= n; ++i) {
    	int maxv = 1;
    	for (int j = 1; j <= n; ++j) {
    		f[i][j] = f[i - 1][j];
    		if (b[j] == a[i]) f[i][j] = std::max(f[i][j], maxv);
    		if (b[j] < a[i]) maxv = std::max(maxv, f[i - 1][j] + 1);
	    	ans = std::max(f[i][j], ans);
    	}
    }

    std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
