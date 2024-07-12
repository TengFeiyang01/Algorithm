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
    ll n;
    std::cin >> n;
	std::vector<std::string> a(n);
	for (auto& s : a) std::cin >> s;
	bool one = false;
	int zero = 0;
	int ans = -1;

	auto check = [&](std::string s) ->int {
		if (s[0] == '0') return -1;
		if (s[0] == '1') {
			for (int i = 1; i < s.size(); ++i)
				if (s[i] != '0')
					return 0;
			return 1;
		}
		return 0;
	};

	int id = -1;
	int i = 0;
	for (auto s : a) {
		int t = check(s);
		if (t == 1) {
			zero += std::count(all(s), '0');
		} else if (t == 0) {
			id = i;
		} else if (t == -1) {
			ans = 0;
		}
		i += 1;
	}	
	if (ans == 0) std::cout << 0;
	else {
		if (id != -1) {
			std::cout << a[id];
			for (int i = 0; i < zero; ++i)
				std::cout << 0;
		} else {
			std::cout << 1;
			for (int i = 0; i < zero; ++i)
				std::cout << 0;
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
