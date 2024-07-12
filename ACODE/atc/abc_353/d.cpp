#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), cnt(11), len(n);
    i64 res = 0, tot = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	len[i] = int(std::to_string(a[i]).size());
    	cnt[len[i]]++;
    	tot += a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
    	cnt[len[i]]--;
    	tot -= a[i];

    	i64 cur = a[i];
    	res = (res + tot) % mod;
    	for (int j = 1; j <= 10; ++j) {
    		cur = cur * 10 % mod;
    		if (cnt[j]) {
    			res = (res + cur * cnt[j]) % mod;
    		}
    	}
    }

    std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
