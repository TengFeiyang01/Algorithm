#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int n, k;
    std::cin >> n >> k >> s;
    std::vector<int> cnt(26);
    for (auto c : s) {
    	cnt[c - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; ++i) {
    	if (cnt[i] % 2) {
    		odd++;
    	}
    }
    if (k >= odd - 1) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
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