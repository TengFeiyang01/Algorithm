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
    int need = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (i) {
    		need += abs(a[i] - a[i - 1]);
    	}
    }
    if (need == 0) {
    	std::cout << "1\n";
    	return;
    }

    int pre = a[0];
	int i = 0, start = 0, ans = 0, v = 0;
	while (i < n) {
		start = i;
		v = a[i];
		while (i < n and a[i] == v) ++i;
		if (start and i < n and a[start - 1] < v == (a[i] < v))
			ans++;
	}
	std::cout << ans + 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
