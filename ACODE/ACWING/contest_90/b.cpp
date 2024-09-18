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
    int n, s;
    std::cin >> n >> s;

	if (s == 0 && n > 1) {
	    std::cout << "-1 -1";
	    return;
	}

 	if (s > 9 * n) {
		std::cout << "-1 -1";
		return;
	}
	
	std::vector<int> a(n);
    std::vector<int> b(n);
    b[0] = 1;
    int t = s;
    for (int i = 0; i < n; ++i) {
    	if (t >= 9) {
    		a[i] = 9;
    		t -= 9;
    	} else {
    		a[i] = t;
    		break;
    	}
    }
    s -= 1;
    for (int i = n - 1; i >= 0; --i) {
    	if (s >= 9) {
    		b[i] += 9;
    		s -= 9;
    	} else {
    		b[i] += s;
    		break;
    	}
    }
	for (auto c : b) std::cout << c;
    std::cout << " ";

    for (auto c : a) std::cout << c;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
