#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 tot = 0LL;
    int n, v;
    std::cin >> n >> v;
    std::vector<i64> a(n), b(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        tot += a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }

    auto check = [&](long double k) -> bool {
    	for (int i = 0; i < n; ++i) {
    		long double need = (long double)a[i] / tot * k;
    		if (need > b[i]) {
    			return false;
    		}
    	}
    	return true;
    };

    long double l = 0, r = v;
    while (r - l > 1e-6) {
    	long double mid = (l + r) / 2;
    	if (check(mid)) {
    		l = mid;
    	} else {
            r = mid;
    	}
    }
    std::cout << std::fixed << std::setprecision(4) << l << "\n";
}

int main() {


    solve();

    return 0;
}
