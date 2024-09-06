#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    std::vector<i64> pre(n + 2), suf(n + 2);
    std::vector<i64> precnt(n + 2), sufcnt(n + 2);
    s = " " + s;
    for (int i = 1; i <= n; ++i) {
    	if (s[i] == 'r') {
    		pre[i] += i;
    		precnt[i]++;
    	} 
    	precnt[i] += precnt[i - 1];
    	pre[i] += pre[i - 1];
    }
    for (int i = n; i >= 0; --i) {
    	if (s[i] == 'd') {
    		suf[i] += i;
    		sufcnt[i]++;
    	}
    	sufcnt[i] += sufcnt[i + 1];
    	suf[i] += suf[i + 1];
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
    	if (s[i] == 'e') {
    		ans += precnt[i - 1] * suf[i + 1] - pre[i - 1] * sufcnt[i + 1];
    	}
    }

    std::cout << ans * 2 <<"\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
