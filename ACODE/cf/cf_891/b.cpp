#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	int la = n;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] >= '5' and i and s[i - 1] != '9') {
			s[i - 1]++;
			la = i;
		}
	}
	if (s[0] >= '5') {
		std::cout << 1 << std::string(n, '0') << "\n";
	} else {
		for (int i = 0; i < la; ++i) {
			std::cout << s[i];
		}
		for (int i = la; i < n; ++i) {
			std::cout << "0";
		}
		std::cout << "\n";
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
