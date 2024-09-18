#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int x = 40, y = -40;
    int id1 = 0, id2 = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        if (a[i] < x) {
            x = a[i];
            id2 = i;
        } 
        if (a[i] > y) {
            y = a[i];
            id1 = i;
        }
    }
    std::vector<PII> ans;

    if (x < 0) {
        for (int i = 0; i < 5; ++i) {
            ans.push_back({id2 + 1, id2 + 1});
        }
        for (int i = 0; i < 5; ++i) {
            ans.push_back({id2 + 1, 1});
        }
        for (int i = n - 1; i >= 1; --i) {
            ans.push_back({1, i + 1});
            ans.push_back({1, 1});
        }
    } else {

        for (int i = 0; i < 5; ++i) {
            ans.push_back({id1 + 1, id1 + 1});
        }
        for (int i = 0; i < 5; ++i) {
            ans.push_back({id1 + 1, n});
        }

        for (int i = 0; i < n - 1; ++i) {
            ans.push_back({n, i + 1});
            ans.push_back({n, n});
        }
    }

    std::cout << ans.size() << "\n";
	for (auto [p, q] : ans) {
		std::cout << q << " " << p << "\n";
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
