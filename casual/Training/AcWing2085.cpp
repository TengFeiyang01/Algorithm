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
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    auto get = [&](std::string s, int t)->int {
    	int ans = 0;
		for (const auto& c : s) {
			ans = ans * t + c - '0';
		}
		return ans;
    };
    std::string s, t;
    std::cin >> s >> t;
    std::set<int> st;
    for (auto &c : s) {
		c ^= 1;
		st.insert(get(s, 2));
		c ^= 1;
    }
    for (auto &c : t) {
    	char m = c;
    	for (int i = 0; i < 3; ++i) {
    		c = i + '0';
    		int x = get(t, 3);
    		if (st.count(x)) {
    			std::cout << x << "\n";
    			return;
    		}
    	}
    	c = m;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
