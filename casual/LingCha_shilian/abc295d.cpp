#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    i64 ans = 0, x = 0;
    std::map<int, int> cnt;
    cnt[0] = 1;
    for (auto &c : s) {
    	x ^= 1 << (c - 'a');
    	ans += cnt[x];
    	cnt[x] += 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}