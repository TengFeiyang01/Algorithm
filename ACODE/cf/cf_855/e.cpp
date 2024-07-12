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
    int n, k;
    std::cin >> n >> k;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> c(26);
    for (int i = 0; i < n; ++i) {
    	if(i < k && i + k >= n) {
    		if (s[i] != t[i]) {
    			std::cout << "NO\n";
    			return;
    		}
    	}
		c[s[i] - 'a']++;
		c[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
    	if (c[i]) {
    		std::cout << "NO\n";
    		return;
    	}
    }
    std::cout << "YES\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
