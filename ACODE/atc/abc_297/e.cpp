#include <bits/stdc++.h>
 
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
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> a(n);
    ll l = 1, r = 1e15;

    for (int i = 0; i < n; ++i)
    	std::cin >> a[i];
   	
   	std::sort(all(a));
   	std::set<ll> s;
   	s.insert(0);
   	ll u = 0;
   	for (int i = 0; i <= k; ++i) {
   		auto it = s.begin();
   		u = *s.begin();
   		for (auto v : a) {
   			ll ne = v + u;
   			s.insert(ne);
   		}
   		s.erase(u);
   	}

   	std::cout << u;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
