#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::map<int, int> cnt;
    for (auto c : s) {
    	cnt[c]++;
    }
    int odd = 0, even = 0;
    for (auto [_, v] : cnt) {
    	if (v % 2) {
    		odd++;
    	} else {
    		even++;
    	}
    }

    if (odd == 0 or odd & 1) {
    	std::cout << "First\n";
    	return;
    } else {
    	std::cout << "Second\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
