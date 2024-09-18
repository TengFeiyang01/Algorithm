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
    std::vector<int> a(n);
    std::vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::sort(all(a));
    int l = -1, r = -1;

    std::unordered_set<int> st;
    for (int i = 1; i <= m; ++i) st.insert(m);
    for (int i = m; i >= 1; --i) {
    	for (auto it = st.begin(); it != st.end(); ++it) {
    		if (i % (*it) == 0) {
    			it.erase(*it);
    		}
    	}
    }

    for (int i = 0; i < n; ++i) {

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
