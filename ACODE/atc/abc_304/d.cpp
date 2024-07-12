#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;

//正难则反 不去统计每块多少草莓  转而去统计每个草莓在哪一块
void solve() {
    int H, W, N;
    std::cin >> W >> H >> N;
    std::vector<PII> a(N);
    for (auto &[x, y] : a) std::cin >> x >> y;
    int A, B;
	std::cin >> A;
	std::vector<int> row(A);
	for (int i = 0; i < A; ++i) std::cin >> row[i];
	std::cin >> B;
	std::vector<int> col(B);
	for (int i = 0; i < B; ++i) std::cin >> col[i];
	std::map<std::pair<int, int>, int> cnt;
	for (auto &[p, q] : a) {
		int x = std::lower_bound(row.begin(), row.end(), p) - row.begin();
		int y = std::lower_bound(col.begin(), col.end(), q) - col.begin();
		cnt[{x, y}]++;
	}
	int mn = N, mx = 0;
	for (auto [_, x] : cnt) {
		mn = std::min(mn, x);
		mx = std::max(mx, x);
	}
	if (cnt.size() != 1LL * (A + 1) * (B + 1)) mn = 0;
	std::cout << mn << " " << mx << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
