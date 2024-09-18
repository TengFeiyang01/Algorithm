#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int mod = 1e9+7;

void solve() {
    int n;
    std::cin >> n;
    std::string t, s;
    std::cin >> s;
    i64 a = 0, b = 0, c = 0;
    for (int i = 1; i < n; ++i) {
    	if (i and s[i - 1] == '1' and s[i] == '1') {
    		a++;
    	}
    	if (s[i] == '4') {
    		b += a;
    		b %= mod;
    	}
    	if (s[i] == '5') {
    		c += b;
    		c %= mod;
    	}
    }
    std::cout << c << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
