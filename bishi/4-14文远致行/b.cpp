#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::string s;
    std::cin >> n >> s >> m;
    std::vector<int> count(26);
    for (auto c : s) 
        ++count[c - 'A'];
    int max_t = *std::max_element(count.begin(), count.end());
    int cnt = 0;
    for (auto&&num : count) 
        cnt += (num == max_t);
    std::cout << std::max(n, (max_t - 1) * (m + 1) + cnt) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
