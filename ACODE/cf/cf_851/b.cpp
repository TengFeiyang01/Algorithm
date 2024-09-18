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
	
	int x = 0, y = 0;
	int bt = 1;
	int ok = 0;
	while (n) {
		int t = n % 10;
		int a = t / 2;
		if (t % 2 == 1) {
			ok++;
			x += bt * (a + ok % 2);
			y += bt * (a + (ok + 1) % 2);
		} else {
			x += bt * a;
			y += bt * a;
		}
		bt *= 10;
		n /= 10;
	}
	
	std::cout << x  << " " << y << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
