#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::map<char, int> cnt;
    for (auto c : s) {
    	cnt[c]++;
    }
    std::string t = "xiaohong";
    std::cout << t;
    for (auto c : t) {
    	cnt[c]--;
    }
    for (auto [x, c] : cnt) {
    	std::cout << std::string(c, x);
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
