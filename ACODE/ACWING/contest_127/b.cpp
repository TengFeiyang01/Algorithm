#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, a, b, fb = 0;
	std::cin >> n >> a >> b;
	int cnt = 0;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		if (x == 1) {
			if (a) {
				a--;
			} else if (b) {
				b--;
				fb++;
			} else if (fb) {
				fb--;
			} else {
				cnt += x;
			}
		} else {
			if (b) {
				b--;
			} else {
				cnt += 2;
			}
		}
	}
	std::cout << cnt << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}