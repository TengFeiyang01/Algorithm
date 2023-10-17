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
    int n, m;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
    	std::cin >> m;
    	a[i % 3] += m;
    }
   	std::string aa = "chest", b = "biceps", c = "back";
   	if (a[0] == *max_element(all(a))) {
   		std::cout << aa << "\n";
   	} else if (a[1] == *max_element(all(a))) {
   		std::cout << b << "\n";
   	} else {
   		std::cout << c << "\n";
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
