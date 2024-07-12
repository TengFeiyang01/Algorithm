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
    //a1 a2 a3
    //   b1  b2
    std::vector<int> a(n), b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
    	std::cin >> b[i];
    }
    a[n - 1] = b[n - 2];
    a[0] = b[0];
    for (int i = 1; i < n - 1; ++i)
        a[i] = std::min(b[i], b[i - 1]);

   	for (int i = 0; i < n; ++i)
   		std::cout << a[i] << " \n"[i == n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
