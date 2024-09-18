#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
    std::string s;
    std::cin >> n >> s;
    s = "#" + s + "#";
    n += 2;

    //f[i]是以i结尾的个数 j是i之前的最短的回文串 f[i] = f[j] + 1
    std::vector<int> f(n), p(n), stk;
    i64 ans = 0;
    for (int i = 1, cur = 0; i + 1 < n; ++i) {
    	if (p[cur] + cur > i) {
    		p[i] = std::min(p[cur] + cur - i, p[2 * cur - i]);
    	}
    	while (s[i + p[i] + 1] == s[i - p[i]]) {
    		p[i]++;
    		cur = i;
    	}

    	stk.push_back(i - 1);
    	while (stk.size()) {
    		int x = stk.back();
    		if (p[x] + x < i) {
    			stk.pop_back();
    		} else {
    			int l = 2 * x - i;
    			f[i] = f[l] + 1;
    			break;
    		}
    	}
    	ans += f[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
