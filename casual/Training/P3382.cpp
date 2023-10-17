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
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    double l, r;
    std::cin >> n >> l >> r;
    std::vector<double> a(n + 1);
    for (int i = n; i >= 0; --i) std::cin >> a[i];

    auto f = [&](double x) -> double{
    	double s = 0;
    	for (int i = n; i >= 0; --i) {
    		s = s * x + a[i];
    	}
    	return s;
    };

    while (r - l > 1e-7) {
    	double k = (r - l) / 3.0;
    	double mid1 = l + k, mid2 = r - k;
    	if (f(mid1) > f(mid2)) r = mid2;
    	else l = mid1;
    }
    printf("%.5lf\n", l);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
