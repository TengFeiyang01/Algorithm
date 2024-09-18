#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    
    std::vector<int> l(k), r(k);
    for (int i = 0; i < k; ++i) {
    	std::cin >> l[i];
        l[i]--;
    }
    for (int i = 0; i < k; ++i) {
    	std::cin >> r[i];
        r[i]--;
    }
    int q;
    std::cin >> q;
    std::vector<int> a(n + 1);

    for (int i = 0; i < q; ++i) {
        int x;
        std::cin >> x;
        --x;
        int idx = std::ranges::upper_bound(l, x) - l.begin() - 1;
        int left = std::min(x, r[idx] + l[idx] - x), right = std::max(x, r[idx] + l[idx] - x);
        a[left] ^= 1;
        a[right + 1] ^= 1;
    }
    
    for (int i = 1; i < n; ++i) {
        a[i] ^= a[i - 1];
    }
    for (int i = 0; i < k; ++i) {
        int left = l[i], right = r[i];
        while (left < right) {
            if (a[left]) {
                std::swap(s[left], s[right]);
            }
            left++;
            right--;
        }
    }

    std::cout << s << "\n";
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