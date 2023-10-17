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

int calc(int k) {
	int res = 0, cnt = 0;
	for (int i = 1, sum = 0; i <= n; ++i) {
		sum += nums[i], cnt++;

		if (sum == k) {
			sum = 0, res += cnt - 1, cnt = 0;
		} else if (sum > k) return N;
	}
	return res;
}

/*
求数列和 sum
枚举 sum 的所有因子
*/

void solve() {
    ll sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> nums[i], sum += nums[i];
    if (sum == 0) {
    	std::cout << "0\n";
    } else {
    	int ans = N;
    	for (int i = 1; i <= sum / i; ++i)
    		if (sum % i == 0)
    			ans = std::min(ans, std::min(calc(i), calc(sum / i)));
    	std::cout << ans << "\n";
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
