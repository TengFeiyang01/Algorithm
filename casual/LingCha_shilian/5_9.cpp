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
	ll x, y, ans;
	std::string s;
	std::cin >> n >> x >> y >> s;
	int zero = 0;
	bool ok = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0' and ok) {
			zero += 1;
			ok = false;
		}
		if (s[i] == '1') {
			ok = true;
		}
	}
	if (!zero) {
		std::cout << "0\n";
	} else {
		std::cout << std::min(y * zero, (zero - 1) * x + y);
	}
}	

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
	solve();

    return 0;
}
