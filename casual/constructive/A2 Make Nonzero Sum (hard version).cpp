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
	std::cin >> n;
	std::vector<int> a(n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		s += a[i];
	}
	//考虑整个数组的和，为奇数时，每次分段变化是偶数，因而无解
	//为偶数时，令 t = |s| / 2，那么我们需要操作 t次，若和大于0，那我们找1的位置x 将[x-1, x]分段，此时1变为-1 
	if (s % 2) {
		std::cout << "-1\n";
	} else {
		if (s == 0) {
			std::cout << n << "\n";
			for (int i = 1; i <= n; ++i) {
				std::cout << i << " " << i << "\n";
			}
		} else if (s > 0) {
			int t = s / 2;
			std::cout << n - t << "\n";
			for (int i = 0; i < n; ++i) {
				if (i + 1 < n and a[i + 1] == 1 and t) {
					std::cout << i + 1 << " " << i + 2 << "\n";
					i++;
					t--;
				} else {
					std::cout << i + 1 << " " << i + 1 << "\n";
				}
			}			
		} else {
			int t = -s / 2;
			std::cout << n - t << "\n";
			for (int i = 0; i < n; ++i) {
				if (i + 1 < n and a[i + 1] == -1 and t) {
					std::cout << i + 1 << " " << i + 2 << "\n";
					i++;
					t--;
				} else {
					std::cout << i + 1 << " " << i + 1 << "\n";
				}
			}

		}
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
