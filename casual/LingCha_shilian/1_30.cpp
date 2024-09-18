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
	ll n, k; 
    std::cin >> n >> k;
    std::vector<ll> a(n);
    for (ll &v : a) std::cin >> v;
    std::vector<int> id(n);
    iota(all(id), 0);
    
    std::sort(all(id), [&](int i, int j){
    	return a[i] < a[j];
    });

    ll d = 0, s = 0;

    for (auto i : id) {
    	d = a[i] - s;
    	if (d) {
    		if (k <= d * n) {
    			s += k / n;
    			k %= n;
    			break;
    		} 
    		s += d;
    		k -= n * d;
    	}
    	--n;
    }
    for (ll &v : a) {
    	if (v <= s) v = 0;
    	else {
    		v -= s;
    		if (k) {
    			--v;
    			--k;
    		}
    	}
    	std::cout << v << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
