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
ll sum1[N]{0}, sum2[N]{0}, a[N];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	sum1[i] = sum1[i - 1] + a[i];
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
    	sum2[i] = sum2[i - 1] + a[i];
    }
    int op, l, r;
    std::cin >> m;
    while (m--) {
    	std::cin >> op >> l >> r;
    	if (op == 1) {
    		std::cout << sum1[r] - sum1[l - 1] << "\n";
    	} else {
    		std::cout << sum2[r] - sum2[l - 1] << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
