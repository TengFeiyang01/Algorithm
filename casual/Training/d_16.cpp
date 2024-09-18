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
const int N = 5e5 + 13;

void solve() {
	int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> sum(N + 1, 0);
    for (int i = 0; i < n; ++i) {
    	int t, c;
    	std::cin >> t >> c;
    	sum[std::max(0, t - c + 1)]++;
    	sum[t + 1]--;
    }

    for (int i = 1; i < N; ++i) {
    	sum[i] += sum[i - 1]; 
    }

    while (m--) {
    	int q;
    	std::cin >> q;
    	std::cout << sum[q + k] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
