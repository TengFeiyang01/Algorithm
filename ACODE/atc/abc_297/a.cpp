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
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (int &v : a) std::cin >> v;
    std::sort(all(a));
	if (n == 1) {
		std::cout << "-1";
		return;
	} else {
		for (int i = 1; i < n; ++i) {
			if (a[i] - a[i - 1] <= d) {
				std::cout << a[i];
				return;
			}
		}
	}
	std::cout << "-1";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}