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

void solve() {
    int k;
    std::cin >> n >> k;
    std::priority_queue<PII> q;
    std::vector<PII> v(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> v[i].second;
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> v[i].first;
    	v[i].first *= -1;
    }
    int tot = k;
    for (int i = 0; i < n; ++i) q.push(v[i]);

    while (k > 0 && q.size()) {
    	if (q.top().second - tot > 0) {
    		k += q.top().first;
    		tot += k;
    	} else {
    		q.pop();
    	}
    }
    if (k > 0) std::cout << "YES\n";
    else std::cout << "No\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
