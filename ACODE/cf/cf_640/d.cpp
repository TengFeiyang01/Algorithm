#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    int alice = 0, bob = 0, last = 0;
    int l = 0, r = n - 1;
    int cnt = 0;

    while (l <= r) {
    	int s = 0;
    	while (s <= last and l <= r) {
    		s += a[l];
    		l++;
    	}
    	alice += s;
        cnt++;
    	if (s > last) {
	    	last = s;
    	} else {
    		break;
    	}

    	if (l > r) break;
    	s = 0;
    	while (s <= last and l <= r) {
    		s += a[r];
    		r--;
    	}
    	bob	+= s;
   		cnt++;
    	if (s <= last) {
    		break;
    	} else {
    		last = s;
    	}
    	if (l > r) break;
    }

    std::cout << cnt << " " << alice << " " << bob << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}