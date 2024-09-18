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

std::string t;

void init() {
	for (int i = 1; i < 400; ++i) {
		if (i % 3 == 0) {
			t = t + 'F';
		} 
		if (i % 5 == 0) {
			t = t + 'B';
		}
	}
}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    if (t.find(s) != -1) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	init();
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
