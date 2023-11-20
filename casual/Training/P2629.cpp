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
const int N = 2e6 + 13;
int n, m, nums[N];
ll sum[N];

void solve() {
    std::cin >> n;
    //首先断环成链
    for (int i = 1; i <= n; ++i) {
    	std::cin >> nums[i];
    	nums[i + n] = nums[i];
    }
    for (int i = 1; i <= n * 2; ++i) sum[i] = sum[i - 1] + 0LL + nums[i];
    std::deque<int> dq;
	int ans = 0;
	//使用单调队列维护每一个长度为 n 的区间的最小前缀和，如果当前区间的最小前缀和>=0, ans++
	for (int i = 1; i <= 2 * n - 1; ++i) {
		while (!dq.empty() && sum[dq.back()] >= sum[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= n) {
			while (!dq.empty() && dq.front() <= i - n) dq.pop_front();
			if (sum[dq.front()] - sum[i - n] >= 0) ans++;
		}
	}
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
