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
    int n;
    int one = 0, zero = 0, other = 0;
    std::cin >> n;
    std::vector<ll> a(n);
    std::map<ll, int> mp;
    for (ll &c : a) {
    	std::cin >> c;
    	if (c == 0) zero++;
    	else if (c == 1) one++;
    	else other++;
    }

	if (zero >= (n - zero) + 2) {
		if (one == 0) std::cout << "1\n";
		else if (other) std::cout << "1\n";
		else std::cout << "2\n";
	} else {
		std::cout << "0\n";
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
