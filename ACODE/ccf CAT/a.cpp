#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> minp, primes, sum, cnt;

void seive(int n) {
	minp.assign(n + 1, 0);
	sum.assign(n + 1, 1);
	cnt.assign(n + 1, 0);
	primes.clear();

	for (int i = 2; i <= n; ++i) {
		if (minp[i] == 0) {
			minp[i] = i;
			cnt[i] = 1;
			primes.push_back(i);
		}

		for (auto p : primes) {
			if (i * p > n) {
				break;
			}
			minp[i * p] = p;

			if (i % p == 0) {
				sum[i * p] = sum[i] / cnt[p] * (cnt[p] + 1);
				break;
			} else {
				sum[i * p] = p * sum[i];
			}
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	seive(n);
	int ans = 0;
	for (int i = 1; i <= 12; ++i) {
		std::cout << sum[i] << " " << cnt[i] << "\n";
	}
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}