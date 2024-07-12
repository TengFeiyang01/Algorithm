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
    std::string s;
    std::cin >> n >> s;
    std::vector<int> q;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
    	if (s[i] != s[j]) {
    		q.push_back(j);
    	}
    }
    int ok = 1;
    for (int i = 1; i < q.size(); ++i) {
    	if (abs(q[i] - q[i - 1]) != 1) {
    		ok = 0;
    	}
    }
    if (ok) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
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
