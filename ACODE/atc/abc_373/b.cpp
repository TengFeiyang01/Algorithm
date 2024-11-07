#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::vector<int> pos(26);
    std::cin >> s;
    for (int i = 0; i < 26; ++i) {
    	pos[s[i] - 'A'] = i;
    }
    int ans = 0;

    for (int i = 1; i < 26; ++i) {
    	ans += abs(pos[i] - pos[i - 1]) % 26;
    }
    std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
