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
int n, k;

/*  
    首先，操作1是这么个逻辑：一旦跳过一个操作1，那么后面的所有操作1都要跳过。
    所以，本质上是选择一个操作1，然后跳过这个操作1之后的所有操作1。可以设想最前面有个 set x = 0的虚拟操作1

    然后，对于选中的那个操作1，由于要跳过其后的所有操作1，所以会消耗掉一些 k 。
    剩下的那些跳过的次数，就是看这个被选中的操作1后面的所有操作2里，操作数从小到大删掉所有负数。所以需要一个堆来记录所有负数的操作2
*/



PII op[N];
void solve() {
    std::cin >> n >> k;
    op[0] = {1, 0};
    for (int i = 1; i <= n; ++i) {
    	auto&[x, y] = op[i];
    	std::cin >> x >> y;
    }
    std::priority_queue<ll> pq;
    ll ans, s = 0;
    ans = -1e18;
    for (int i = n; i >= 0; --i) {
    	auto[t, y] = op[i];
        if (t == 1) {
            ans = std::max(ans, s + y);
            --k;
        } else {
            if (y > 0) s += y;
            else {
                pq.push(y);
            }
        } 
        if (k < 0) break;
        while (pq.size() > k) {
            s += pq.top();
            pq.pop();
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
