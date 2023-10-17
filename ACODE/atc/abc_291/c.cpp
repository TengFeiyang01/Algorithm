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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<PII, int> mp;
    mp[{0, 0}] = 1;
    int x = 0, y = 0;
    for (char c : s) {
    	if (c == 'L') {
    		x--;
    	} else if (c == 'R') {
    		x++;
    	} else if (c == 'U') {
    		y--;
    	} else if (c == 'D') {
    		y++;
    	}
		if (mp.count({x, y})) {
			std::cout << "Yes\n";
			return;
		}
        mp[{x, y}]++;
    }
    std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}
