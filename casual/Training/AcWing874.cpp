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
    std::vector<int> prime;
    std::vector<int> phi(n + 1);
    phi[1] = 1;


    std::vector<int> st(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
    	if (!st[i]) {
    		prime.pb(i);
    		phi[i] = i - 1;
    	}
    	for (int j = 0; prime[j] <= n / i; ++j) {
    		int p = prime[j];
    		st[p * i] = 1;
    	    if (i % p == 0) {
    	    	phi[p * i] = phi[i] * p;
    	    	break;
    	    }
    	    phi[p * i] = phi[i] * (p - 1);
    	}
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) res += phi[i];
	std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
