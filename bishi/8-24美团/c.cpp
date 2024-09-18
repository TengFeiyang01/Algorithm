#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1000000007;

void solve() {
	std::vector<i64> a(3);
	i64 k;
	std::cin >> a[0] >> a[1] >> a[2] >> k;
	std::sort(a.begin(), a.end());
	i64 dif = a[2] - a[0] + a[2] - a[1];
	if (k >= dif) {
		k -= dif;
		a[2] += k / 3;
		a[0] = a[2] + k / 3;
		a[1] = a[2] + k / 3;
		for (int j = 0; j < k % 3; ++j) {
			a[j]++;
		}
	} else {
		if (k >= a[1] - a[0]) {
			k -= a[1] - a[0];
			a[0] = a[1] + (k + 1) / 2;
			a[1] += k / 2;
		} else {
			a[0] += k;
		}
	}
	i64 ans = 1;
	for (auto x : a) {
		x %= mod;
		ans = ans * x % mod;
	}
	std::cout << ans << "\n";
}

using namespace std;
int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

