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
int n, m, nums[N];
int c, d, k;
void solve() {
    std::cin >> c >> d;
    std::cin >> n >> m >> k;
    if (k >= n * m) {
    	std::cout << "0\n";
    	return;
    }
    int sum = n * m;
    int dif = sum - k;
    int c1 = (dif + n - 1) / n * c;
    int c2 = dif / n * c + dif % n * d;
    int c3 = dif * d;
    int ans = std::min(c1, std::min(c2, c3));
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
