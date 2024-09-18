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

std::string ans, a, t;
int f = 0;

void solve() {

    if (std::cin >> a) {
		if (a == "pair") {
			ans += "pair<";
			solve();
			ans += ',';
			solve();
			ans += '>';
		} else {
			ans += "int";
		}
    } else {
    	f = 1;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	std::cin >> a;
    solve();
	if (std::cin >> t) f = 1;
	if (f) {
		std::cout << "Error occurred";
	} else {
		std::cout << ans;
	}

    return 0;
}
