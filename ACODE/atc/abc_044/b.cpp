#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    std::map<char, int> cnt;
    for (auto c : s) cnt[c]++;
    for (auto[c, v] : cnt) {
    	if (v % 2) {
    		std::cout << "No\n";
    		return;
    	}  
    }
    std::cout << "Yes\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
