#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
	int l = 1, r = n;
	int p = 0;
	while (r - l > 1) {
		int mid = l + r >> 1;
		std::cout << "+ " << n - mid << std::endl;
		int d;
		std::cin >> d;
		if (d > p) {
			l = mid;
		} else {
			r = mid;
		}
		l = (l + n - mid) % n;
		r = (r + n - mid) % n;
		if (r == 0) r = n;
		p = d;
	}
	std::cout << "! " << p * n + l << std::endl;

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
