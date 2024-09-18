#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> cnt(26);
    for (int i = 0; i < n;) {
    	int j = i;
    	while (j < n and s[j] == s[i]) j++;
    	cnt[s[i] - 'a'] = std::max(cnt[s[i] - 'a'], j - i);
    	i = j;
    }
    std::cout << std::accumulate(cnt.begin(), cnt.end(), 0) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
