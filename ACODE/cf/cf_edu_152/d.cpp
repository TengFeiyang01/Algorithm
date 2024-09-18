#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	
	// std::vector<int> r(n);
	// std::iota(r.begin(), r.end(), 0);

	// std::vector<int> lst(n), nxt(n, n - 1);
	// for (int i = 0; i < n - 1; ++i) {
	// 	lst[i + 1] = a[i] == 0 ? i : lst[i];
	// }


	// for (int i = n - 1; i > 0; --i) {
	// 	nxt[i - 1] = a[i] == 0 ? i : nxt[i];
	// }

	// for (int i = 0; i < n; ++i) {
	// 	if (a[i] == 1) {
	// 		r[lst[i]] = std::max(r[lst[i]], i);
	// 		r[i] = std::max(r[i], nxt[i]);
	// 	} else if (a[i] == 2) {
	// 		r[lst[i]] = std::max(r[lst[i]], nxt[i]);
	// 	}
	// }

	// for (int i = 1; i < n; ++i) {
	// 	r[i] = std::max(r[i], r[i - 1]);
	// }

	// for (int i = 0; i < n; i = r[i] + 1) {
	// 	ans++;
	// }

	for (int i = 0; i < n; ++i) {
		if (i and a[i - 1]) {
			//被前面染色
			continue;
		} else if (a[i] == 0 and i + 1 < n and a[i + 1]) {
			//被后面染色
			a[i + 1]--;
		} else {
			//自己染色
			ans++;
		}
	}

	std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
