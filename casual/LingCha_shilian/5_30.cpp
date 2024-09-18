#include <bits/stdc++.h>

void solve() {
	long long a, b, k;
	std::cin >> a >> b >> k;
	std::vector<int> prime;
	prime.push_back(a - 1);
	std::vector<bool> np(b + 1);

	for (int i = 2; i <= b; ++i) {
		if (!np[i]) {
			if (i >= a) {
				prime.emplace_back(i);
			}
			for (long long j = (long long)i * i; j <= b; j += i) {
				np[j] = true;
			}
		}
	}
	prime.push_back(b + 1);
	int m = prime.size();
	if (m - 2 < k) {
		std::cout << "-1\n";
		return;
	}
	int ans = 0;
	for (int i = k; i < m; ++i) {
		ans = std::max(ans, prime[i] - prime[i - k]);
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
