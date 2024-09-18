#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s, ans;
    std::cin >> n >> s;
    int cnt = 0;
    for (auto c : s) {
    	if (c == ')' and cnt) {
    		while (ans.back() != '(') {
    			ans.pop_back();
    		}
    		ans.pop_back();
    		cnt--;
    	} else {
    		cnt += c == '(';
    		ans += c;
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