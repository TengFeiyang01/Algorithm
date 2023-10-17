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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    vector c(n);
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
    	std::cin >> m;
    	while (m--) {
    		int p;
    		std::cin >> p;
    		c[i].push_back(p);
    		mp[p]++;
    	}
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
    	int cnt = 0;
    	int org = mp.size();
    	for (auto v : c[i]) {
    		if (mp[v] > 1) {
    			cnt++;
    		}
    	}
    	if (cnt == c[i].size()) {
    		ok = true;
    		break;
    	}

    }
    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
