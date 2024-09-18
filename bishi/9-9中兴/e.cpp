#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int l = 1, r = n;

	auto check = [&](int x) {

		std::unordered_map<int, int> cnt;
		std::multiset<int> freq;
		
		for (int i = 0; i < x - 1; ++i) {
			cnt[a[i]]++;
		}
		
		for (auto [k, v] : cnt) {
			freq.insert(v);
		}
		
		for (int i = x-1; i < n; ++i) {
			int p;
			if (freq.count(a[i])) {
				p = cnt[a[i]];
				freq.erase(freq.find(p));
			}
			cnt[a[i]]++;
			freq.insert(cnt[a[i]]);
			int mx = *freq.rbegin();
			if (x - mx <= k) {
				return true;
			}
			p = cnt[a[i - x + 1]];
			freq.erase(freq.find(p));
			cnt[a[i - x + 1]]--;
			freq.insert(cnt[a[i - x + 1]]);
		}
		return false;
	};
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
