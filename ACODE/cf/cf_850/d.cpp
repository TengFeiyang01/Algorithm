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
    std::vector<std::pair<std::string, int>> s2;
    std::vector<std::pair<std::string, int>> s3;
    std::vector<std::string> a(n);
	std::set<int> st;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		std::sort(all(a[i]));
		for (int j = 0; j < 3; ++j) {
			st.insert(a[i][j]);
		}
		if (st.size() == 3) continue;
		else if (st.size() == 2) s2.eb(a[i], i + 1);
		else s3.eb(a[i], i + 1);
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
