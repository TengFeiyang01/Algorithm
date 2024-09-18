#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<char, int> cnt;
    int ans = 0;
    for (auto c : s) {
    	if (isupper(c)) {
    		c = tolower(c);
    		if (cnt[c]) {
    			cnt[c]--;
    		} else {
    			ans++;
    		}
    	} else {
    		cnt[c]++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
