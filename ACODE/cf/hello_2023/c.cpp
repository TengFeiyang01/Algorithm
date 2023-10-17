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
const int N = 2e5 + 13;
ll n, m, nums[N];

void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> nums[i];
   	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
   	ll ans = 0, sum = 0;
   	for (int i = m; i < n; ++i) {
   		if (nums[i] < 0) pq.push(nums[i]);
   		sum += nums[i];
   		while (sum < 0) {
   			int x = pq.top();
   			x *= -1;
   			pq.pop();
   			sum += (2 * x);
   			ans++;
   		} 
   	}
   	if (nums[m - 1] <= 0) sum = nums[m - 1];
   	else if (m != 1) {
   		sum = -1 * nums[m - 1];
   		ans++;
   	}
   	std::priority_queue<int> q;
   	for (int i = m - 2; i >= 1; --i) {
   		if (nums[i] > 0) {
   			q.push(nums[i]);
   		}
   		sum += nums[i];
   		while (sum > 0) {
   			int x = q.top();
   			q.pop();
   			sum -= 2 * x;
   			ans++;
   		}
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
