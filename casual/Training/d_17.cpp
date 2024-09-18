#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <unordered_set>
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
const int N = 5e5 + 13;

void solve() {
	ll n, L, S, ans = 0;
	std::cin >> n >> L >> S;
    std::unordered_map<ll, int> st;
	std::vector<PII> trees;

    int x, y;
	for (int i = 0; i < n; ++i) {
	    std::cin >> x >> y;
        st[(ll)x * (L + 1) + y] = 1;	  
        trees.eb(x, y);
	}
    
    int che[53][53];	
	for (int i = S; i >= 0; --i)
	    for (int j = 0; j <= S; ++j)
	        std::cin >> che[i][j];

	
	auto check = [&](ll x, ll y)->bool {
	    for (int i = 0; i <= S; ++i)
	        for (int j = 0; j <= S; ++j) {
                int tx = x + i, ty = j + y;
                if (tx > L || ty > L || st.count((ll)tx * (L + 1) + ty) != che[i][j]) return false;
	        }
	    return true;
	};
	        
    for (auto[x, y] : trees) {
        if (check(x, y)) ans++;
        //std::cout << x << " " << y << "\n";
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}