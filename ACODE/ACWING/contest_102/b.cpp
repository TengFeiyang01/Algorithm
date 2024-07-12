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
    ll n, x = 1;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	x = std::lcm(x, a[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }
    }
    std::sort(all(a));
    if (a[0] != a[n - 1]) ok = false;
    if (ok) std::cout << "Yes\n";
    else std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
	solve();

    return 0;
}
