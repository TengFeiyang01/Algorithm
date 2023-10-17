#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
	std::cin >> n;
	ll x, dif;
	std::cout << n << "\n";
	for (int i = 1; i <= n; ++i) {
		std::cin >> x;
		dif = (1 << (int)(log2(x) + 1)) - x;
		std::cout << i << " " << dif << "\n";
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
