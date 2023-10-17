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
    if (n == 1) {
        std::cout << n << "\n";
        return;
    }
    if (n % 2) {
        std::cout << "-1\n";
        return;
    }
    int pre = 1, suf = n;
    std::vector<int> b;
    while (pre < suf) {
    	b.push_back(pre++);
    	b.push_back(suf--);
    }
    std::cout << n << " ";
    for (int i = 1; i < n; ++i) {
        std::cout << ((b[i] - b[i - 1]) % n + n) % n << " \n"[i == n - 1];
    }
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
