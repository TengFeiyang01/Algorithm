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
    ll a, b;
    std::cin >> a;
 	std::vector<int> s(33);
 	int t = 0;
 	for (int i = 0; i < 32; ++i) {
 		s[i] = (a >> i) & 1;
 		if (s[i] == 1) {
 			t = i;
 		}
 	}
    t = 1 << t;
 	int ok = 1;
 	for (int i = 31; i > 0; --i) {
 		if (s[i] == s[i - 1] && (s[i] == 1)) 
 			ok = 0;
 	}
    if (a % 2) ok = 0;
 	ll b1 = 0, b2 = 0;
 	b2 = t + a / 2;
    b1 = (2 * a - b2);
 	if (ok) {
 		std::cout << b2 << " " << b1 << "\n";
 	} else {
 		std::cout << "-1\n";
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
