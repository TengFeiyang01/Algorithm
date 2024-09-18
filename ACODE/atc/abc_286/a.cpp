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
    int n, l1, l2, r1, r2;
    std::cin >> n >> l1 >> r1 >> l2 >> r2;
    std::vector<int> a(1 + n);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    int k = l2 - l1;
	for (int i = l1; i <= r1; ++i) {
		std::swap(a[i], a[i + k]);
	}

    for (int i = 1; i <= n; ++i) std::cout << a[i] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
