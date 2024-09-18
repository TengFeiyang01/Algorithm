#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	std::string pre, suf;

	std::vector<int> cnt(26);
	std::ranges::sort(s);
	int n = s.size();
	int i = 0;
	for (; i < n - 1; i += 2) {
		if (s[i] != s[i + 1]) {
			if (s[i + 1] == s[n - 1]) {
				std::swap(s[i], s[(i + n) / 2]);
			} else {
				suf += s[i];
				i++;
			}
			break;
		}
		pre += s[i];
		suf += s[i];
	}
	std::ranges::reverse(suf);
	std::cout << pre << s.substr(i) << suf << "\n";
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