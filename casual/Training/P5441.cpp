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
	int n;
    std::cin >> n;
    if (n == 1) {
    	std::cout << "0\n" << "0\n";
    	return;
    }
    std::cout << n * (n - 3LL) * (n * n + 6 * n - 31) / 48 << "\n";
   	int k = (n + 1) / 2;
   	for (int i = 1; i <= n; ++i) {
   		int a[n + 1]{0};
   		for (int j = 1; j <= k; ++j)
   			a[(i + j - 1) % n + 1] = 1;
   		for (int j = 1; j <= n; ++j) std::cout << a[j] << " \n"[j == n];
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
