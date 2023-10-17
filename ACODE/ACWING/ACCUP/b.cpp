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
    ll n, m;
    std::cin >> n >> m;
    std::vector<int> a;
    while (m) {
    	a.push_back(m % n);
    	m /= n;
    }
    bool ok = true;
    for (int i = 0; i < sz(a); ++i) {
    	if (a[i] != 1 and a[i] and a[i] != n - 1)
    		ok = false;
    	else if (a[i] == n - 1 || a[i] == n) {
    		a[i + 1]++;
    	}
    }
    if (ok) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
