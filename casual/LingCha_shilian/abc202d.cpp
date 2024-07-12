#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int a, b;
    i64 k;
    std::cin >> a >> b >> k;
    int mx = 61;
    std::vector C(mx, std::vector<i64>(mx));
    for (int i = 0; i < mx; ++i) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    std::string s = std::string(a + b, 'a');

    for (int i = 0; i < s.size(); ++i) {
    	if (k > C[a + b - 1][b]) {
    		k -= C[a + b - 1][b];
    		s[i] = 'b';
    		b--;
    	} else {
    		a--;
    	}
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}