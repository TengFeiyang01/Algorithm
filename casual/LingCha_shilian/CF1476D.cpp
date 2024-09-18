#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    s = " " + s;
    std::vector<int> l(n + 1), r(n + 1);
    l[1] = r[n] = 1;
    for (int i = 2; i <= n; ++i) {
    	if (s[i] != s[i - 1]) {
    		l[i] = l[i - 1] + 1;
    	} else {
            l[i] = 1;
        }
    }
    for (int i = n - 1; i > 0; --i) {
    	if (s[i] != s[i + 1]) {
    		r[i] = r[i + 1] + 1;
    	} else {
            r[i] = 1;
        }
    }

    for (int i = 0; i <= n; ++i) {
    	int x = (s[i] != 'L' or !i) ? 0 : l[i];
    	int y = (i == n or s[i + 1] != 'R') ? 0 : r[i + 1];
    	std::cout << x + y + 1 << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
