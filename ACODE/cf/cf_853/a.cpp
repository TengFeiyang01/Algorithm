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
    std::vector<int> a(n);
    for (int &v : a) std::cin >> v;
	int g;
 
	int ok = 1;
   	std::sort(all(a));
   	for (int i = 0; i < n - 1; ++i) {
   		for (int j = i + 1; j < n; ++j) {
   			g = std::__gcd(a[i], a[j]);
	   		if (g <= 2) {
	   			std::cout << "YES\n";
	   			return;
	   		}
   		}
   	}


	std::cout << "NO\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
