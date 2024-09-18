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
    
    int x, a0 = -1, a1 = -1, up = 0;

    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	if (i == 0) {
            a0 = a1 = x;
            std::cout << 1;
        } else if (up) {
            if (x >= a1 and x <= a0) {
                std::cout << 1;
                a1 = x;
            } else {
                std::cout << 0;
            }
        } else if (x >= a1) {
            std::cout << 1;
            a1 = x;
        } else if (x <= a0) {
            std::cout << 1;
            up = 1;
            a1 = x;
        } else {
            std::cout << 0;
        }
    }
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
