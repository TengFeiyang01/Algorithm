#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> cnt(501), cnt2(501);
    int mn = 5000, mx = 0;
    for (int i = 0; i < n; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	if (l != r) {
    		cnt[l]++;
	    	cnt[r]++;
    	} else {
    		cnt[l]++;
    	}
    	if (l + 1 < r) {
	    	cnt2[l + 1]++;
	    	cnt2[r]--;
    	}
    	mn = std::min(mn, l);
    	mx = std::max(mx, r);
    }
    int mod = 1000000007;

    for (int i = 1; i <= 500; ++i) {
    	cnt2[i] += cnt2[i - 1];
    }


    i64 ans = 0, p = 1;
    for (int i = 0; i < 501; ++i) {
    	if (cnt2[i] % 2) {
    		if (i == mn or i == mx) {
    			ans += p;
    		}
    	} 

    	if (i > mn and i < mx and cnt2[i]) {
    		ans += p;
    	}
    	p = p * 2 % mod;
    	ans %= mod;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
