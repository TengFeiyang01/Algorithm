#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = unsigned long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    ll n;
    std::string s;
    std::cin >> s >> n;
	int m = s.size();
	
	ll x = 0;
	for (int i = 0; i < m; ++i) {
		if (s[i] == '1') {
			x |= 1LL << (m - i - 1);
		}
	}
	if (x > n) {
		std::cout << "-1";
		return;
	}

	for (int i = 0; i < m; ++i) {
		if (s[i] == '?') { 
			ll t = 1LL << (m - i - 1);
			if (t + x > n) {
				continue;
			} else{
				x += t;
			}
		} 
	} 

	std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
