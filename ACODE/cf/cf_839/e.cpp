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
    int tot = 0, a = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
    	int s;
    	std::cin >> s;
    	a += i != s;
    	b += n - i + 1 != s;
    	tot += i != s and n - i + 1 != s;
    }
    //由于a先手，所以先手可以取 等号
    if (a + tot <= b) {
    	std::cout << "First\n";
    } else if (b + tot < a) {
	    //b + tot == a 时，a和b都不会取染色那个tot的位置 陷入死循环
    	std::cout << "Second\n";
    } else {
    	std::cout << "Tie\n";
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
