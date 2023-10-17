#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
  	if (cnt[a[0]] < k or cnt[a[n - 1]] < k) {
  		std::cout << "NO\n";
  	} else {
  		if (a[0] == a[n - 1]) {
  			std::cout << "YES\n";
  		} else {
			int l = 0, x = 0;
			while (l < n and x < k) {
				if (a[l] == a[0]) {
					x++;
					if (x == k) break;
				}
				l++;
			}  		
			int r = n - 1;
			x = 0;
			while (r >= 0 and x < k) {
				if (a[r] == a[n - 1]) {
					if (++x == k) break;
				}
				r--;
			}
			if (l > r) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
			}
  		}
  	}
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
