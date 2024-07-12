#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0, cur = 0;
    std::map<int, int> cnt;
    
    for (int i = 0; i < n; ++i) {
    	int x, l, r;
    	char c;
    	std::cin >> x >> c;
    	if (c == 'L') {
    		l = cur - x + 1, r = cur + 1;
    		cur = cur - x + 1;
     	} else {
     		l = cur, r = cur + x;
     		cur = cur + x - 1;
     	}
     	cnt[l]++;
     	cnt[r]--;
    }
    int s = 0, pre = -inf;

    for (auto [l, v] : cnt) {
    	if (pre != -inf) {
    		if (s % 4 == 1) {
    			ans += l - pre;
    		}
    	}
   		pre = l;
    	s += v;
    }


    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
