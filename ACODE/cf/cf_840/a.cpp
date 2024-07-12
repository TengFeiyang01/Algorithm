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
int n, m;

void solve() {
    std::cin >> n;
    int mi = 1023;
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		mi &= x;
		mx |= x;
	}
	std::cout << mx - mi << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
