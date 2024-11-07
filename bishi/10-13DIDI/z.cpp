#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1000000007;

i64 getMinErrors(std::string s, int x, int y) {
	int n = s.size();
	std::vector<int> dp(n);
	i64 cnt1 = 0, cnt0 = 0;
	// 全部变成1
	i64 tot = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			cnt0++;
			tot += cnt1 * y;
		} else {
			cnt1++;
			tot += cnt0 * x;
		}
		tot %= mod;
	}
	i64 ans = 1e18;
	std::cout << tot << "\n";
	ans = std::min(ans, tot);
	i64 suf1 = 0, suf0 = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '!') {
			cnt1--;

			// 10 y
			// 01 x
			// 1 -> 0  -cnt1*x
			tot = (tot - cnt0 * x - suf0 * y + cnt1 * x + suf1 * x);
			suf0++;
		} else if (s[i] == '0') {
			suf0++;
			cnt0--;
		} else {
			suf1++;
			cnt1--;
		}
		ans = std::min(ans, tot);
	}
	return std::max(ans, 0LL);
}

void solve() {
    std::string s;
    int x, y;
    std::cin >> s >> x >> y;
    std::cout << getMinErrors(s, x, y) << "\n";
    std::swap(x, y);
    // std::cout << getMinErrors(s, x, y);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
