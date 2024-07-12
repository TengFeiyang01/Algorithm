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
    std::vector<PII> a(n);
    for (auto &[x, y] : a) std::cin >> x >> y;
    std::sort(all(a));
	int pre = -inf;
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		auto[cur, l] = a[i];
		int ne = INT_MAX;
		if (i + 1 < n) {
			ne = a[i + 1].first;
		}
		if (cur - l > pre) {
			ans++;
			pre = cur;
		} else if (cur + l < ne) {
			ans++;
			pre = cur + l;
		} else {
			pre = cur;
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
