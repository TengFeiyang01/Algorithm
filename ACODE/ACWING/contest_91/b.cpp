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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    while (k--) {
    	int x, y;
    	std::cin >> x >> y;
    	a[x]++;
    	a[y + 1]--;
    }
    for (int i = 1; i <= n; ++i) {
    	a[i] += a[i - 1];
    }
    bool ok = 1;
    int x, y;
    for (int i = 1; i <= n; ++i) {
    	if (a[i] == 0 || a[i] > 1) {
    		ok = 0;
    	  	x = i;
    	  	y = a[i];
            break;
    	}
    }

    if (ok) {
    	std::cout << "OK";
    } else {
		std::cout << x << " " << y;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
