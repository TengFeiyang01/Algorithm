#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    int a = 0, b = 0, ab = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> s;
    	if (s[0] == 'B' and s.back() == 'A') ab++;
    	else if (s[0] == 'B') b++;
    	else if (s.back() == 'A') a++;
    	int m = s.size();
    	for (int j = 0; j < s.size(); ++j) {
    		if (s.substr(j, 2) == "AB") {
    			j++;
    			cnt++;
    		}
    	}
    }
    //如果有 "B...A" 多个 但是没有已经凑好的 "...A + B..." 此时只能凑 ab - 1 个 AB
    std::cout << (std::min(a, b) + cnt + ab - (ab and a == 0 and b == 0));
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}