#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    int l = 0, r = n;
    while (l < r) {
    	int mid = l + r >> 1;
    	bool ok = true;
    	int p = x, logo = mid;
    	for (auto c : s) {
    		if (c == '1') {
    			if (p) {
    				p--;
    			} else if (logo) {
    				logo--;
    			} else {
    				ok = false;
    			}
    		} else if (c == '2') {
    			if (logo) {
    				logo--;
    			} else {
    				ok = false;
    			}
    		} else {
    			p = x;
    			logo = mid;
    		}
    	}
    	if (ok) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << r << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
