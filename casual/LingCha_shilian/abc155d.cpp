#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    int p = std::ranges::lower_bound(a, 0) - a.begin();
    int q = std::ranges::lower_bound(a, 1) - a.begin();
    int c = q - p;


    i64 neg = 1LL * p * (n - q);
    if (k <= neg) {
    	k = neg - k + 1;
    	i64 l = 0, r = 1e18;
    	while (l < r) {
    		i64 mid = l + r >> 1;
    		i64 cnt = 0, j = q;
    		for (int i = 0; i < p; ++i) {
    			while (j < n and a[j] * -a[i] <= mid) {
    				j++;
    			}
    			cnt += j - q;
    		}
    		if (cnt >= k) {
    			r = mid;
    		} else {
    			l = mid + 1;
    		}
    	}

    	std::cout << -l << "\n";
    	return;
    } 

    k -= neg;
    i64 zero = c * (c - 1LL) / 2 + c * (n - c);
    if (k <= zero) {
    	std::cout << "0\n";
    	return;
    }
      
    k -= zero;

    i64 l = 0, r = 1e18;
    while (l < r) {
    	i64 mid = l + r >> 1;
    	i64 cnt = 0, i = 0, j = p - 1;
    	while (i < j) {
    		if (a[i] * a[j] > mid) {
    			i++;
    		} else {
    			cnt += j - i;
    			j--;
    		}
    	}
    	i = q, j = n - 1;
    	while (i < j) {
    		if (a[i] * a[j] > mid) {
    			j--;
    		} else {
    			cnt += j - i;
    			i++;
    		}
    	}
        
    	if (cnt >= k) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}