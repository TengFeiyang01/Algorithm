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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
 	ll n, k;
 	std::cin >> n >> k;
 	std::string s;
 	std::cin >> s;
 	if (n == k) {
 		std::cout << "Yes\n";
 	} else if (n < k) {
 		int t = k % n;
 		int ok = 0;

 		std::cout << t;
 		for (int i = 0, j = t, k = n - t; i < t; ++i, ++j, --k) {
 			if (s[i] == s[j] && s[j] == s[k]) {
 				continue;
 			}
 			if (i == t - 1) ok = 1;
 		}


 		if (ok) {
 			std::cout << "Yes\n";
 		} else {
 			std::cout << "No\n";
 		}

 	} else if (n > k) {
 		int ok = 0;
 		if (n / k == 3) {

 		}

 		if (ok) {
 			std::cout << "Yes\n";
 		} else {
 			std::cout << "No\n";
 		}
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
