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
using PII = std::pair<ll, ll>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    if (n < 5) {
    	std::cout << "YES\n";
    	return;
    } 

    std::vector<PII> a(n);
    for (auto&[x, y] : a) std::cin >> x >> y;

    auto line = [](PII a, PII b, PII c)->bool {
    	return (b.first - a.first) * (c.second - a.second) == (b.second - a.second) * (c.first - a.first);
    };
    auto f = [&](PII p0, PII p1)->bool {
    	std::vector<PII> v;
    	for (auto p : a) {
    		if (!line(p, p0, p1)) {
    			if (sz(v) < 2) {
    				v.pb(p);
    			} else if (!line(v[0], v[1], p)) {
    				return false;
    			}
    		}
    	}
    	return true;
    };

    if (f(a[0], a[1]) || f(a[0], a[2]) || f(a[1], a[2])) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
