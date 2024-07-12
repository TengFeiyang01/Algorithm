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
    std::vector<ll> a(n + 1);
    //std::cout << "0 ";
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	a[i] += a[i - 1];
//    	std::cout << a[i] << " \n"[i == n];
    }
    int m;
    std::cin >> m;
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << a[r] - a[l - 1] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
