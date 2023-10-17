#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(26);
    for (auto c : s) {
    	cnt[c - 'a']++;
    }
    int odd = 0, even = 0;
    for (int i = 0; i < 26; ++i) {
    	if (cnt[i] % 2) odd++; 
    }
    even = n - odd;
    
    int l = 1, r = n + 1;
    while (l < r) {
    	int mid = l + r + 1 >> 1;
    	int ok = 1, p = even, q = odd;
    	for (int i = 0; i < k; ++i) {
    		if (mid % 2) {
    			p -= (mid - 1);
                if (q > 0) {
                    q -= 1;
                } else {
                    p -= 1;
                }
    		} else {
    			p -= mid;
    		}
    		if (p < 0 or q < 0) ok = 0;
    	}
    	if (ok) l = mid;
    	else r = mid - 1;
    }
    std::cout << l << "\n";
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
