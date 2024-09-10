#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::vector<int> row(3), col(3);
	for (int i = 0; i < 3; ++i) {
		std::cin >> row[i];
	}
	for (int i = 0; i < 3; ++i) {
		std::cin >> col[i];
	}
	int need;
	std::cin >> need;
	int ans = 0;
	for (int i = 0; i <= 3; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k <= 3; ++k) {
				for (int p = 0; p <= 3; ++p) {
					for (int q = 0; q <= 3; ++q) {
						for (int o = 0; o <= 3; ++o) {
							for (int x = 0; x <= 3; ++x) {
								for (int y = 0; y <= 3; ++y) {
									for (int z = 0; z <= 3; ++z) {
										int cnt = 0;
										cnt += (i ^ j ^ k) == row[0];
										cnt += (o ^ p ^ q) == row[1];
										cnt += (x ^ y ^ z) == row[2];
										cnt += (i ^ p ^ x) == col[0];
										cnt += (j ^ q ^ y) == col[1];
										cnt += (k ^ o ^ z) == col[2];
										ans += cnt >= need;
									}
								}
							}
						}
					}
				}
			}
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
