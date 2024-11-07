#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

int get(vector<int> traffics, int minLen, int maxLen, int threshold) {
	int ans = 0, n = traffics.size();
	std::vector<i64> sum(n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] += sum[i - 1] + traffics[i - 1];
	}
	for (int l = 1; l <= n; ++l) {
		// sum[j] - sum[l - 1] > threshold
		int j = std::upper_bound(sum.begin(), sum.end(), sum[l - 1] + threshold) - sum.begin();
		int len = j - l + 1, r = l + maxLen - 1;
		r = std::min(r, n);
		j = std::max(j, l + minLen - 1);
		ans += std::max(0, r - j + 1);
	}
	return ans;
}

void solve() {
	int n, l, r, t;
	std::cin >> n >> l >> r >> t;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::cout << get(a, l, r, t);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
