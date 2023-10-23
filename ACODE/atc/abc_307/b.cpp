#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    bool ok = false;
    std::vector<std::string> s(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto t = s[i] + s[j];
            if (i != j and t == std::string(t.rbegin(), t.rend())) {
                ok = true;
            }
        }
    }
    if (ok) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}