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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, k;

int cnt(int n) {
    int res = 0;
    while (n) {
        res += ((n % 10) == k);
        n /= 10;
    }
    return res;
}

void solve() {
	std::cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) ans += cnt(i);
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
