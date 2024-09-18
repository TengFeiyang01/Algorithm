#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
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
int n, m, nums[N];
ll sum[N];
int l[N], r[N];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> nums[i];
    	sum[i] = sum[i - 1] + nums[i];
        l[i] = 0;
        r[i] = n;
    }
    //找到当前元素左右第一个比它小的元素位置l, r， 则以当前元素为最小值所产生的ans为 sum[r - 1] - sum[l]
    std::stack<int> s;
    ll ans = 0;
    for (int i = n; i >= 1; --i) {
        while (!s.empty() && nums[s.top()] > nums[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && nums[s.top()] > nums[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, (sum[r[i] - 1] - sum[l[i]]) * nums[i]);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}
