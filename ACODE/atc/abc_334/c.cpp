#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::multiset<int> st;
    for (int i = 1; i <= n; ++i) {
    	st.insert(i);
    	st.insert(i);
    }
    
    for (int i = 1; i <= k; ++i) {
    	int x;
    	std::cin >> x;
    	st.erase(st.find(x));
    }

    std::vector<int> a{0};
    for (auto x : st) {
        a.push_back(x);
    }
    
    n = 2 * n - k;
    std::vector<i64> preodd(n + 1), preeven(n + 1);
    std::vector<i64> sufodd(n + 2), sufeven(n + 2);

    for (int i = 1; i <= n; ++i) {
    	preodd[i] = preodd[i - 1];
    	preeven[i] = preeven[i - 1];
    	if (i % 2) {
    		preodd[i] = preodd[i - 1] + a[i];
    	} else {
    		preeven[i] = preeven[i - 1] + a[i];
    	}
    }
    for (int i = n; i >= 1; --i) {
    	sufodd[i] = sufodd[i + 1];
    	sufeven[i] = sufeven[i + 1];
    	if (i % 2) {
    		sufodd[i] = sufodd[i + 1] + a[i];
    	} else {
    		sufeven[i] = sufeven[i + 1] + a[i];
    	}
    }
    if (n % 2 == 0) {
	    i64 ans = 0;
    	for (int i = 2; i <= n; i += 2) {
    		ans += a[i] - a[i - 1];
    	}
    	std::cout << ans << "\n";
    } else {
    	i64 ans = 1e18, pre = 0, suf = 0;
    	for (int i = 1; i <= n; ++i) {
    		if (i % 2) {
    			pre = preeven[i - 1] - preodd[i - 1];
    			suf = sufodd[i + 1] - sufeven[i + 1];
                suf = abs(suf);
    		} else {
    			pre = preodd[i - 1] - preeven[i - 1];
    			suf = sufeven[i + 1] - sufodd[i + 1];
                suf = abs(suf);
    		}
    		ans = std::min(ans, pre + suf);
    	}
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
